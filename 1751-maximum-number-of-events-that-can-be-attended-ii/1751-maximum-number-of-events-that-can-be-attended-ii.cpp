class Solution {
public:
   int s;
   int limit;
   int maxsofar = INT_MIN;
   int returnindex(vector<int>&starttime,int start){
     int ind = upper_bound(starttime.begin(),starttime.end(),start)-starttime.begin();
     if(ind>=0 && ind<s){
       return ind;
     }
     return -1;
     
   }
   int func(vector<vector<int>>&dp,int index ,vector<int>&starttime,vector<vector<int>>&events,int perform){
     if(perform==limit){
       return 0;
     }
     if(index==-1 or index==s){
       return 0;
     }
     if(dp[index][perform]!=-1){
       return dp[index][perform];
     }
     
     
      int end = events[index][1];
      int value = events[index][2];
      int current = returnindex(starttime,end);
      int picked = value+func(dp,current,starttime,events,perform+1);
      int notpicked = func(dp,index+1,starttime,events,perform);
      maxsofar = max(picked,notpicked);
      dp[index][perform] = maxsofar;
      return maxsofar;
      
    
  }
  
  
    int maxValue(vector<vector<int>>& events, int k) {
      int n = events.size();
      vector<int>starttime;
      s = n;
      limit = k;
      vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
      sort(events.begin(),events.end());
      for(auto it : events){
        int st = it[0];
        starttime.push_back(st);
      }
      maxsofar = func(dp,0,starttime,events,0);
      return maxsofar;
      
        
    }
};