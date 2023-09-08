class Solution {
public:
  bool func(int ind , vector<int>&nums,vector<int>&dp){
    int n = nums.size();
    if(ind==n-1){
      return true;
    }
    if(ind>=n){
      return false;
    }
    if(dp[ind]!=-1){
      if(dp[ind]==1){
        return true;
      }
      else{
        return false;
      }
    }
    for(int i = nums[ind] ; i>0 ; i--){
      if(func(ind+i,nums,dp)==true){
        dp[ind] = 1;
        return true;
      }
    }
   dp[ind]=0;
   return false; 
    
  }
  
    bool canJump(vector<int>& nums) {
      
      vector<int>dp(1000000,-1);
      bool flag = func(0,nums,dp);
      return flag;
        
    }
};