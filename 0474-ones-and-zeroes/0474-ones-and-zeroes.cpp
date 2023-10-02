class Solution {
public:
  
  int func(int index , vector<string>&strs,int m,int n,vector<vector<vector<int>>>&dp){
    int s = strs.size();
    if(index==s or m+n==0){
      return 0;
    }
    if(dp[m][n][index]!=-1){
      return dp[m][n][index];
    }
    int pick = 0;
    string temp = strs[index];
    int onecount = count(temp.begin(),temp.end(),'1');
    int zerocount = count(temp.begin(),temp.end(),'0');
    if(zerocount<=m && onecount<=n){
      pick = 1+func(index+1,strs,m-zerocount,n-onecount,dp);
    }
    int nonpick = func(index+1,strs,m,n,dp);
    dp[m][n][index] = max(pick,nonpick);
    return dp[m][n][index];
    
  }
    int findMaxForm(vector<string>& strs, int m, int n) {
      int s = strs.size();
      vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(600,-1)));
      int ans = func(0,strs,m,n,dp);
      return ans;
      
      
      
     
      
      
        
    }
};