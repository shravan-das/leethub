class Solution {
public:
    int minJumps(vector<int>& arr) {
       int n = arr.size();
       map<int,set<int>>mp;
       for(int i = 0 ; i<n ; i++){
         mp[arr[i]].insert(i);
        }
       queue<pair<int,int>>q;
       q.push({0,0});
       vector<int>vis(n+1,0);
       while(!q.empty()){
        int steps = q.front().first;
        int temp = q.front().second;
        q.pop();
        if(temp==n-1){
          return steps;
        }
        if(temp-1>=0){
        mp[arr[temp]].insert(temp-1);
        }
        if(temp+1<n){
        mp[arr[temp]].insert(temp+1);
        }
        for(int num : mp[arr[temp]]){
          if(vis[num]==0){
            vis[num] = 1;
            q.push({steps+1,num});
          }
        }
        mp[arr[temp]].clear();
     }
      
      
      
      return 0;
      
     
      
      
        
      
        
    }
};