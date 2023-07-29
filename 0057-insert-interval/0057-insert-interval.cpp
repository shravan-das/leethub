class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = intervals.size();
      vector<vector<int>>ans;
      for(auto it : intervals){
        if(it[1]<newInterval[0]){
          ans.push_back(it);
        }
        else if(it[0]>newInterval[1]){
          ans.push_back(newInterval);
          newInterval = it;
          
        }
        else{
          newInterval[0] = min(it[0],newInterval[0]);
          newInterval[1] = max(it[1],newInterval[1]);
        }
        
      }
      ans.push_back(newInterval);
      return ans;
      
        
    }
};