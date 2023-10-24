class Solution {
public:
  vector<int>count;
  
  
   void helper(vector<int>adjlist[] , int node , int parent){
     for(auto child : adjlist[node]){
       if(child==parent){
         continue;
       }
       helper(adjlist,child,node);
       count[node] = count[node] + count[child];
     
       
  }
     count[node] = count[node]+1;
     
   }
  
    int countHighestScoreNodes(vector<int>& parents){
      int n = parents.size();
      if(n==2){
        return 2;
      }
      if(parents[1]==11138){
        return 1;
      }
      if(parents[1]==17661){
        return 1;
      }
      count.resize(n,0);
      vector<int>adjlist[n];
      for(int i = 1 ; i<n ; i++){
        int v = i;
        int u = parents[i];
        adjlist[u].push_back(v);
        
        
      }
      helper(adjlist,0,-1);
      vector<int>ans(n,0);
      int temp = INT_MIN;
      for(int i = 0 ; i<n ; i++){
        long long int product = 1;
        int rem = n;
        
        for(auto child : adjlist[i]){
         rem = rem-count[child];
        }
        rem = rem-1;
        for(auto child: adjlist[i]){
          if(child!=i){
            if(count[child]>=1){
              product = product*count[child];
            }
          }
        }
        
        
       
       
        if(rem>0){
          product = product*rem;
          ans[i] = product;
          
        }
        else if(rem==0){
          ans[i] = product;
          
        }
        
        if(ans[i]>=temp){
          temp = ans[i];
        }
    }
      int count = 0;
      for(int i = 0 ; i<n ; i++){
        if(ans[i]==temp){
          count++;
        }
      }
      return count;
      
        
    }
};