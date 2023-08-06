class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
      priority_queue<pair<int,int>>pq;
      int n = boxTypes.size();
      for(int i = 0 ; i<n ; i++){
        int trucks = boxTypes[i][0];
        int units = boxTypes[i][1];
        pq.push({units,trucks});
      }
      int count = truckSize;
      int profit = 0;
      while(!pq.empty() && count>0){
        int units = pq.top().first;
        int trucks = pq.top().second;
        pq.pop();
        if(trucks>count && count>0){
          profit = profit+count*units;
          break;
        }
        profit = profit+trucks*units;
        count = count-trucks;
    }
      
      return profit;
        
    }
};