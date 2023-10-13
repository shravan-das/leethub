class Solution {
public:
  int func(int num,vector<int>&dp){
    if(num==2){
      return 1;
    }
    if(num==3){
      return 2;
    }
    if(dp[num]!=-1){
      return dp[num];
    }
    int ans = INT_MIN;
    for(int i = 1 ; i<=num-1 ; i++){
      int temp = i*max(num-i,func(num-i,dp));
      ans = max(ans,temp);
      dp[num] = ans;
    }
    
   
    return dp[num];
  }
  
    int integerBreak(int n) {
      
      
      vector<int>dp(n+1,-1);
      return func(n,dp);
        
    }
};