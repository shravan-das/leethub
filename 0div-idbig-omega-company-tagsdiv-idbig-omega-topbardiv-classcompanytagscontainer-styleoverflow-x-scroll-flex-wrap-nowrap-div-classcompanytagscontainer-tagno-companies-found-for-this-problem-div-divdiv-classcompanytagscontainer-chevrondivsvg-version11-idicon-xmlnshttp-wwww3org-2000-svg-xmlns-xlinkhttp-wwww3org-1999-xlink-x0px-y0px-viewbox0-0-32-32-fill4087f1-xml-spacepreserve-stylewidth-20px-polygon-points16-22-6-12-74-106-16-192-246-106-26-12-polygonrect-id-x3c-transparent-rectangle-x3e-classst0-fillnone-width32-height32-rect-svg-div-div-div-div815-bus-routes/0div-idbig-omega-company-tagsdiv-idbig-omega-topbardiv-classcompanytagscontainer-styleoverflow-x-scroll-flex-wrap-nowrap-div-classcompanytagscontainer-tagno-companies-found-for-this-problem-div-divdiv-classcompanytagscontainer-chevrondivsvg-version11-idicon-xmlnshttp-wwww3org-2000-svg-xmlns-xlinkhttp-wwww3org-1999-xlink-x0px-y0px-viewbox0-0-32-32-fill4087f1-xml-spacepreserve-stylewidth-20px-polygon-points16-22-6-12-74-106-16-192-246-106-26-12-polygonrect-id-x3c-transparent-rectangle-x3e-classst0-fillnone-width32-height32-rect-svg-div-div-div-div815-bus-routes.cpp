class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
      int n = routes.size();
      vector<int>vis(100000,0);
      vector<int>busvis(1000,0);
      vector<int>adjlist[100000];
      int curr;
      for(int i = 0 ; i<n ; i++){
        vector<int>temp = routes[i];
        int n = temp.size();
        for(int j = 0 ; j<n; j++){
          int num = routes[i][j];
          adjlist[num].push_back(i);
        }
        
        
      }
      
      queue<pair<int,int>>q;
      q.push({source,0});
      while(!q.empty()){
        int node = q.front().first;
        int bus = q.front().second;
        if(node==target){
          return bus;
        }
        q.pop();
        for(auto it : adjlist[node]){
          if(!busvis[it]){
            for(auto iter : routes[it]){
              if(vis[iter]==1){
                continue;
              }
              vis[iter] = 1;
              q.push({iter,bus+1});
            }
            busvis[it] = 1;
          }
          
        }
          
          
        
      }
      return -1;
      
      
        
    }
};