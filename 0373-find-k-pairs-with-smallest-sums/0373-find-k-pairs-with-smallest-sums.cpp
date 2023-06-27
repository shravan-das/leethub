class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();  
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
   for(int i = 0 ;i<n ; i++){
     pq.push({nums1[i]+nums2[0],{i,0}});
   }
      vector<vector<int>>ds;
      while(k){
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        ds.push_back({nums1[i],nums2[j]});
        if(j!=m-1){
          pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        k--;
        if(pq.empty()==true){
          break;
        }
        
        
      }
      
      return ds;
      
        
    }
};