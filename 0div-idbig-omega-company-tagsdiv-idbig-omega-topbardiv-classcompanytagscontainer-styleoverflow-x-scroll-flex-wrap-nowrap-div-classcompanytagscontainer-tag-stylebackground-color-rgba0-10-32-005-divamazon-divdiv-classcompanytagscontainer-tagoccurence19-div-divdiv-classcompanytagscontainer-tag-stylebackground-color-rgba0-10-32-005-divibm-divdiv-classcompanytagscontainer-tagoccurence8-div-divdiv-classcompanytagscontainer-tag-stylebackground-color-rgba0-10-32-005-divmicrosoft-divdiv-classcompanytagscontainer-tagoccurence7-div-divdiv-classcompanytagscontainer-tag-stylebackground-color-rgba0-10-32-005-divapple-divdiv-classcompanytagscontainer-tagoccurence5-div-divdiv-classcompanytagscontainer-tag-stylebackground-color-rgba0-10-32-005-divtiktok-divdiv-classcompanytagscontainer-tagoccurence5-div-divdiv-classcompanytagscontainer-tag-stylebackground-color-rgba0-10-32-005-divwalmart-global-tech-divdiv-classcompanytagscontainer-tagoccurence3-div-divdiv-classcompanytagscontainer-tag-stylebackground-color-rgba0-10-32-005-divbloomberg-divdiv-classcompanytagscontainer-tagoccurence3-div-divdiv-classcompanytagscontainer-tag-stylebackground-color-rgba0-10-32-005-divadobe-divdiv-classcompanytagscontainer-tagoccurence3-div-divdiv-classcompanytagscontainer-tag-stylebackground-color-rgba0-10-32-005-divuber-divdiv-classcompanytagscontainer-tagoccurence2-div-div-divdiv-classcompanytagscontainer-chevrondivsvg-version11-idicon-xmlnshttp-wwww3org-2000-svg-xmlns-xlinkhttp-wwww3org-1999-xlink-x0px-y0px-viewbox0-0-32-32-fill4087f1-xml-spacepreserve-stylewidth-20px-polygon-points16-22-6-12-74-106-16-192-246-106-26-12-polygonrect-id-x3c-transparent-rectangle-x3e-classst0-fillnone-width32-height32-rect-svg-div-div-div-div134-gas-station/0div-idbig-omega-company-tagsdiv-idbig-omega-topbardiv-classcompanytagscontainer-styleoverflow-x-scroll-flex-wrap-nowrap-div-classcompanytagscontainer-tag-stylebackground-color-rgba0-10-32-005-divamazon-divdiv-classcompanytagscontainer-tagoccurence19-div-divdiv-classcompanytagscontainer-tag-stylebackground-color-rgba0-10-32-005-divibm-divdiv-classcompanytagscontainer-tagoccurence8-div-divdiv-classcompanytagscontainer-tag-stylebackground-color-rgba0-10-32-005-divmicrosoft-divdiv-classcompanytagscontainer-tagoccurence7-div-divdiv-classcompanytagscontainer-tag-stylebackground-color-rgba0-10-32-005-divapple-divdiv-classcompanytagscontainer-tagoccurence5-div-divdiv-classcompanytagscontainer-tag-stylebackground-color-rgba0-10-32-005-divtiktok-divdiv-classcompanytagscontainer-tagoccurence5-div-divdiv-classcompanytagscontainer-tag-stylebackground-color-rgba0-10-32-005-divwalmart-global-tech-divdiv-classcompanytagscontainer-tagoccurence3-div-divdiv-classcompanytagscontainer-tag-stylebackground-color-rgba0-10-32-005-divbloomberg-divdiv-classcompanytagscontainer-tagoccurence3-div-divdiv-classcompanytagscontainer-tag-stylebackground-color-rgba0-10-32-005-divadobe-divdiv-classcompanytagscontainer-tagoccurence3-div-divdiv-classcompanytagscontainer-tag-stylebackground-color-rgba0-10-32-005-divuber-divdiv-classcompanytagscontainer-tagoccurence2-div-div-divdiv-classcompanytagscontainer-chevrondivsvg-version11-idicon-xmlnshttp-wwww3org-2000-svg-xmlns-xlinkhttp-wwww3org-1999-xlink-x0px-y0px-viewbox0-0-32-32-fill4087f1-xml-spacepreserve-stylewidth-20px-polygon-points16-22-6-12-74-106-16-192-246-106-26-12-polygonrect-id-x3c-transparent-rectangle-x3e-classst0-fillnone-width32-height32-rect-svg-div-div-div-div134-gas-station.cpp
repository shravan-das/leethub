class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int gassum = 0;
      int costsum = 0;
      int n = gas.size();
      for(int i = 0 ; i<n ; i++){
        gassum = gassum+gas[i];
        costsum = costsum + cost[i];
      }
      if(costsum>gassum){
        return -1;
      }
      int sum = 0;
      int start = 0;
      for(int i = 0 ; i<n ; i++){
        sum = sum+gas[i]-cost[i];
        if(sum<0){
          start = i+1;
          sum = 0;
        }
        
      }
      return start;
        
    }
};