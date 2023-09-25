class Solution {
public:
    
    int func(int m , int n , string &text1 , string &text2 , vector<vector<int>>&dp ){
        
        if(m==0 || n==0 ){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        if(text1[m-1]==text2[n-1]){
            dp[m][n] = 1 + func(m-1,n-1,text1,text2,dp);
            return dp[m][n];
        }
        else{
        dp[m][n] = max(func(m-1,n,text1,text2,dp) , func(m,n-1,text1,text2,dp));
        return dp[m][n];
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(1005,vector<int>(1005,-1));
        return func(m , n , text1 , text2 , dp);
        
       
       
        
        
        
        
    }
};