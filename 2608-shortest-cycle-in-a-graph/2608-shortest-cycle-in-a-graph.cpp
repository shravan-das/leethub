class Solution {
public:
   int ans = INT_MAX;
   vector<int>dist;
   vector<int>par;
   void func(int source,vector<vector<int>>&adjlist,queue<int>q,int n){
     vector<int>dist(n+1,INT_MAX);
     vector<int>par(n+1);
     dist[source] = 0;
     q.push(source);
      while(!q.empty()){
       int node = q.front();
       q.pop();
       for(auto it : adjlist[node]){
         
         if(dist[it]==INT_MAX){
           par[it] = node;
           dist[it] = 1+dist[node];
           q.push(it);
         }
         else if(dist[it]!=INT_MAX && par[it]!=node && par[node]!=it){
           int temp = dist[it]+dist[node]+1;
           ans = min(ans,temp);
         }
       }
     }
     
   }
   
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
      vector<vector<int>>adjlist(n+1);
      for(auto it : edges){
        int u = it[0];
        int v = it[1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
      }
      for(int i = 0 ; i<n ; i++){
        queue<int>q;
        func(i,adjlist,q,n);
      }
      if(ans==INT_MAX){
        return -1;
      }
      
      return ans;
        
    }
};