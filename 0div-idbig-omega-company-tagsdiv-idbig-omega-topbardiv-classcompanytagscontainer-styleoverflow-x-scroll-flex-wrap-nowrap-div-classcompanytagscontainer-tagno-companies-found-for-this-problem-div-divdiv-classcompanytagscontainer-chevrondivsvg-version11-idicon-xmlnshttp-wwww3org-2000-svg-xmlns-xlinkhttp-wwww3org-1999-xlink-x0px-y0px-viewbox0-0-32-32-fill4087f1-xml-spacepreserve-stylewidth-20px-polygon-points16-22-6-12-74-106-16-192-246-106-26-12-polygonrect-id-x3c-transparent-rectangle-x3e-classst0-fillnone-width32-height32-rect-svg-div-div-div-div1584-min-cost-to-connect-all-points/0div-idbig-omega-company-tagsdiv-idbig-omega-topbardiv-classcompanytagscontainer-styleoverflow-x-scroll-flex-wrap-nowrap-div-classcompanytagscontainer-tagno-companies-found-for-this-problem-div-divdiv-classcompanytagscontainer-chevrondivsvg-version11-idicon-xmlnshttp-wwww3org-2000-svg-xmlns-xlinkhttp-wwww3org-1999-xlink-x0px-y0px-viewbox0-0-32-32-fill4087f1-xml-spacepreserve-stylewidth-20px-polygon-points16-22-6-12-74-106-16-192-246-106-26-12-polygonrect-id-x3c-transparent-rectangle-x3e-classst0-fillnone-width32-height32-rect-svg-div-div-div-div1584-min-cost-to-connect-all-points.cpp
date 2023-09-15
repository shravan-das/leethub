class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();
      vector<vector<int>>adjlist[n];
      for(int i = 0 ; i<n-1 ; i++){
        int p1 = points[i][0];
        int p2 = points[i][1];
        int coord1 = i;
        for(int j = i+1 ; j<n ; j++){
          int coord2 = j;
          int p3 = points[j][0];
          int p4 = points[j][1];
          int dist = abs(p1-p3)+abs(p2-p4);
          adjlist[coord1].push_back({dist,coord2});
          adjlist[coord2].push_back({dist,coord1});
      }
        
    }
      priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>>pq;
      vector<int>vis(n,0);
      int sum = 0;
      pq.push({0,0});
      while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node]==1){
          continue;
        }
        vis[node] = 1;
        sum = sum+dist;
        for(auto it : adjlist[node]){
          int adjnode = it[1];
          int edgewt = it[0];
          if(vis[adjnode]==0){
            pq.push({edgewt,adjnode});
          }
        }
      }
      return sum;
    }
};