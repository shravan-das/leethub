class Solution {
public:
  int n;
    int func(int index , vector<int>& nums,int prev,vector<vector<int>>&dp){
      if(index==n){
        return 0;
      }
       int res = 0;
       if(dp[index][prev+1]!=-1){
         return dp[index][prev+1];
       }
      
       if(prev==-1 or nums[index]>nums[prev]){
        res = 1+func(index+1,nums,index,dp);
      }
      
       res = max(res,func(index+1,nums,prev,dp));
       dp[index][prev+1] = res;
     
      return res;
    
      
      
    }
    int lengthOfLIS(vector<int>& nums) {
      n = nums.size();
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
      int ans = func(0,nums,-1,dp);
      return ans;
      
        
    }
};