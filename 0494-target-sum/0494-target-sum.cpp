class Solution {
public:
  int totsum = 0;
  int t;
  int func(int i ,vector<vector<int>>&dp , vector<int>& nums , int sum){
    if(i==nums.size() && sum==t){
      return 1;
     }
    else if(i==nums.size()){
      return 0;
    }
   
   if(dp[sum+totsum][i]!=-1){
     return dp[sum+totsum][i];
   }
   int addsign = func(i+1,dp,nums,sum+nums[i]);
   int subsign = func(i+1,dp,nums,sum-nums[i]);
   dp[sum+totsum][i] = addsign + subsign;
   return dp[sum+totsum][i];
  }

    int findTargetSumWays(vector<int>& nums, int target) {
      int n = nums.size();
      t = target;
      
      for(auto it : nums){
        totsum = totsum+it;
      }
      vector<vector<int>>dp(2*totsum+1,vector<int>(n,-1));
      int ans = func(0,dp,nums,0);
      return ans;
        
    }
};