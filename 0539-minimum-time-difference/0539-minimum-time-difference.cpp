class Solution {
public:
    int findMinDifference(vector<string>& timePoints){
      int count = 0;
      int n = timePoints.size();
      int max_hour = 0;
      int max_min = 0;
      priority_queue<pair<int,int>>pq;
      for(int i = 0 ; i<n ; i++){
         string temp = timePoints[i];
         string hour = temp.substr(0,2);
         string min = temp.substr(3,2);
         int currmin = stoi(min);
         int currhr = stoi(hour);
         if(currmin==0 && currhr==0){
           count++;
         }
         if(count==2){
          return 0;
         }
        pq.push({currhr,currmin});
      }
      max_hour = pq.top().first;
      max_min = pq.top().second;
      int prevhour = max_hour;
      int prevmin = max_min;
      int diff = INT_MAX;
      pq.pop();
      while(!pq.empty()){
        int minh = pq.top().first;
        int minm = pq.top().second;
        pq.pop();
        diff = min(diff,(prevhour*60+prevmin)-(minh*60+minm));
        
        prevhour = minh;
        prevmin = minm;
       
      }
      int a = max_hour*60+max_min;
      int b = (24+prevhour)*60+prevmin;
      int c = b-a;
      int finalans = min(diff,c);
      return finalans;
      
      
      
    
        
    }
};