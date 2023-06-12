class Solution {
public:
  bool flag;
  int starnode;
  int temp = 0;
  
   void func(int start,vector<int>adjlist[],vector<int>&vis,int count){
    if(vis[start]==1 && start==starnode){
      temp = count;
      flag = false;
      return;
    }
    else if(vis[start]==1){
      return;
    }
     vis[start] = 1;
   
     for(auto it : adjlist[start]){
       func(it,adjlist,vis,count+1);
    }
       
     if(flag==false){
       return;
     }
     vis[start] = 0;
     
     
    
  }
  
    int longestCycle(vector<int>& edges){
      int n = edges.size();
      vector<int>adjlist[n];
      vector<int>ind(n,0);
      vector<int>vis(n,0);
      for(int i = 0 ;i<n ; i++){
        int u = edges[i];
        if(u!=-1){
        adjlist[i].push_back(u);
        ind[u]++;
        }  
      }
      int ans = -1;
      for(int i = 0 ; i<n ; i++){
        starnode = i;
        flag = true;
        int count = 0;
        if(ind[i]!=0 && vis[i]==0){
          func(i,adjlist,vis,count);
          ans = max(ans,temp);
         }
        temp = 0;
      }
      
      if(ans==0){
        return -1;
      }
      return ans;
      
      
    }
};