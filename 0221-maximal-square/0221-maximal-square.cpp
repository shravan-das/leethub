class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int rowsize = matrix.size();
      int colsize = matrix[0].size();
      vector<vector<int>>dp(rowsize,vector<int>(colsize));
      int maxans = 1;
      int finans = 0;
      
      for(int i = 0 ; i<rowsize ; i++){
        for(int j = 0 ; j<colsize ; j++){
          if(matrix[i][j]=='1'){
            finans = 1;
          }
          if(i==0 or j==0){
            if(matrix[i][j]=='1'){
              dp[i][j] = 1;
            }
            else{
              dp[i][j] = 0;
            }
            continue;
          }
          int left = dp[i][j-1];
          int top = dp[i-1][j];
          int topleft = dp[i-1][j-1];
          if(left && top && topleft && matrix[i][j]=='1'){
            dp[i][j] = min(min(left,top),topleft)+1;
            maxans = max(maxans,dp[i][j]);
          }
          else{
            if(matrix[i][j]=='1'){
              dp[i][j] = 1;
            }
            else{
              dp[i][j] = 0;
            }
          }
        }
      }
      
      if(finans==0){
        return 0;
      }
      
      return maxans*maxans;
      
        
    }
};