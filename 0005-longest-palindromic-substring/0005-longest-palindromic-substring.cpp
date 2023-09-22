class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
      vector<vector<int>>dp(n,vector<int>(n,0));
      string ans;
      int maxi = INT_MIN;
      for(int i = n-1 ; i>=0 ; i--){
        for(int j = i ; j<n ; j++){
          if(i==j){
            dp[i][j] = 1;
            if(dp[i][j]>maxi){
            maxi = max(maxi,dp[i][j]);
            ans = s.substr(i,1);
            } 
            continue;
          }
          else if(j-i==1){
            if(s[i]==s[j]){
              dp[i][j] = 2;
              if(dp[i][j]>maxi){
              maxi = max(maxi,dp[i][j]);
              ans = s.substr(i,2);
              } 
              continue;
            }
          }
          else if(s[i]==s[j] && dp[i+1][j-1]>0){
            if(s[i]==s[j] && dp[i+1][j-1]>0){
              dp[i][j] = 2+dp[i+1][j-1];
              if(dp[i][j]>maxi){
                maxi = dp[i][j];
                ans = s.substr(i,j-i+1);
              }
            }
          }
        }
      }
      
      return ans;
        
    }
};