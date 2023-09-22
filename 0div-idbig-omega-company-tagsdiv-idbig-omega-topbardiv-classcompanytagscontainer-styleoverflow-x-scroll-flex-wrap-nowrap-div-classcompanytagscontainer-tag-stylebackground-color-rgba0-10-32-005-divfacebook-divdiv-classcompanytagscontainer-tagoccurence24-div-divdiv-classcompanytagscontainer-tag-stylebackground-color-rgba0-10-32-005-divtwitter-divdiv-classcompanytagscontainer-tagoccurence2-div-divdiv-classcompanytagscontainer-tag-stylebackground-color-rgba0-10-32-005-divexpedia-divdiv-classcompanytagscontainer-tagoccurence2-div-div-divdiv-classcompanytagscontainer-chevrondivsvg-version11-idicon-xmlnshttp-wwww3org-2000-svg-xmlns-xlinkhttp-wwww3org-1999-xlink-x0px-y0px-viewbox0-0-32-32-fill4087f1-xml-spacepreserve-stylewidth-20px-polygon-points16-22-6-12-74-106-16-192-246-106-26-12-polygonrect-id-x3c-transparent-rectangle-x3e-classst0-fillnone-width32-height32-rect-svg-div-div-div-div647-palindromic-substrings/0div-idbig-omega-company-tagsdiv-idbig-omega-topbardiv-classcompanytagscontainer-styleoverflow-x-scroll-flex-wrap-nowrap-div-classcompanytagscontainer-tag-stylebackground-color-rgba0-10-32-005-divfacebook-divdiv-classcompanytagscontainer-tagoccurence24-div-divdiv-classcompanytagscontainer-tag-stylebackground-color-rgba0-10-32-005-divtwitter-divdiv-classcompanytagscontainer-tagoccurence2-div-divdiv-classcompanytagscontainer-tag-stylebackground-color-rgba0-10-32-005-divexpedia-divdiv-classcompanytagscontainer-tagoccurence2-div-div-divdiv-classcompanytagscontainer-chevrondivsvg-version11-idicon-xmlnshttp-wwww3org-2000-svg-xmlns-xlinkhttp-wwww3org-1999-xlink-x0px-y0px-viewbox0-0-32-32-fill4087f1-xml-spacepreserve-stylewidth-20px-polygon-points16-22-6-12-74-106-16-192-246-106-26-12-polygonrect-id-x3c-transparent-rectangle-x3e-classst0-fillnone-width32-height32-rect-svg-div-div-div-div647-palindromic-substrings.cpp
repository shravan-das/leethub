class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = n-1 ; i>=0 ; i--){
          for(int j = i ; j<n ; j++){
            if(i==j){
              count++;
              dp[i][j] = 1;
              continue;
            }
            else if(j-i==1 && s[i]==s[j]){
              dp[i][j] = 2;
              count++;
              continue;
            }
            else if(s[i]==s[j] && dp[i+1][j-1]>0){
              dp[i][j] = 2+dp[i+1][j-1];
              count++;
              continue;
            }
          }
        }
      return count;
    }
};