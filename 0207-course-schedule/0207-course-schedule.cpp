class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it : prerequisites){
          adj[it[1]].push_back(it[0]);
        }
      vector<int>indeg(numCourses);
      for(int i = 0 ; i<numCourses ; i++){
        for(auto it : adj[i]){
          indeg[it]++;
        }
      }
      queue<int>q;
      for(int i = 0 ; i<numCourses ; i++){
        if(indeg[i]==0){
          q.push(i);
        }
      }
      vector<int>topo;
      while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();
        for(auto it : adj[node]){
          indeg[it]--;
          if(indeg[it]==0){
            q.push(it);
          }
        }
        
      }
      if(topo.size()==numCourses){
        return true;
      }
      return false;
    }
};