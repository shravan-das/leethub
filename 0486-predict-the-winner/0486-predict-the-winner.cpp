class Solution {
public:
    int func(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
      if(start==end){
        return nums[start];
      }
      if(dp[start][end]!=INT_MAX){
        return dp[start][end];
      }
      int score1 = nums[start]-func(nums,start+1,end,dp);
      int score2 = nums[end]-func(nums,start,end-1,dp);
      int finalscore = max(score1,score2);
      dp[start][end] = finalscore;
      return dp[start][end];
    }
    
    bool PredictTheWinner(vector<int>& nums){
      int n = nums.size();
      vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
      int score = func(nums,0,n-1,dp);
      if(score>=0){
        return true;
      }
      return false;
      
      
      
      
      
      
        
    }
};