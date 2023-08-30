class Solution {
public:
   int binarysearch(vector<vector<int>>&offers,int idx,int i , int m){
     int ans = offers.size();
     while(i<=m){
       int mid = (i+m)/2;
       if(offers[mid][0]>offers[idx][1]){
         ans = mid;
         m = mid-1;
       }
       else{
         i = mid+1;
        }
     }
     return ans;
   }
   
  
   int func(int i , vector<vector<int>>&offers , vector<int>&dp){
     int m = offers.size();
     if(i==m){
       return 0;
     }
     if(dp[i]!=-1){
       return dp[i];
     }
     int nonpick =  func(i+1,offers,dp);
     int index = binarysearch(offers,i,i,m-1);
     int pick = offers[i][2] + func(index,offers,dp);
     dp[i] = max(nonpick,pick);
     return dp[i];
   }
  
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
      int m = offers.size();
      sort(offers.begin(),offers.end());
      vector<int>dp(m,-1);
      int ans = func(0,offers,dp);
      return ans;
    }
};