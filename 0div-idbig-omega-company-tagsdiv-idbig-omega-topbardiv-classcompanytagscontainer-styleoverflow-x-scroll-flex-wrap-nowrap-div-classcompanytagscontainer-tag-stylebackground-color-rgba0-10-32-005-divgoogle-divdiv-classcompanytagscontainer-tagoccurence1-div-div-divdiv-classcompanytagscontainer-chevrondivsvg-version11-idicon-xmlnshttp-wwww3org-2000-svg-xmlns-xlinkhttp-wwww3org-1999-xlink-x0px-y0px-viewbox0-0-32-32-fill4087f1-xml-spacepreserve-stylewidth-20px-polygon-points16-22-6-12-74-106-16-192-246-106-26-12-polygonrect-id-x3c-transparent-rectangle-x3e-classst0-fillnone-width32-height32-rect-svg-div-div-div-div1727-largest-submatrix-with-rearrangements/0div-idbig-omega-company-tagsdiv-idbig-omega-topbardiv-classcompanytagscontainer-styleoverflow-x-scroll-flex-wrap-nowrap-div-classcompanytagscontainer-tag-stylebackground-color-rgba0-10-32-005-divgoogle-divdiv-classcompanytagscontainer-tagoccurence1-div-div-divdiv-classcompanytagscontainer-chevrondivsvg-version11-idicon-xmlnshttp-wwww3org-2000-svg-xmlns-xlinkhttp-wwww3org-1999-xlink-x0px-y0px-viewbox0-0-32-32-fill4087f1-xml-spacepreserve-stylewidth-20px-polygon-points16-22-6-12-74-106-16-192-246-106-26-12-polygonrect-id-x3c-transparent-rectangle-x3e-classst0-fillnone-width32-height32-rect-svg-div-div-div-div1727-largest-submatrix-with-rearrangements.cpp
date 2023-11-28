class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
      int rowsize = matrix.size();
      int colsize = matrix[0].size();
      for(int j = 0 ; j<colsize ; j++){
        int temp = 0;
        for(int i = 0 ; i<rowsize ; i++){
          
          if(matrix[i][j]==1){
            temp = temp+1;
            matrix[i][j] = temp;
          }
          else if(matrix[i][j]==0){
            temp = 0;
            matrix[i][j] = -1;
          }
        }
        
      }
      
      for(int i = 0 ; i<rowsize ; i++){
        sort(matrix[i].begin() , matrix[i].end() , greater<>());
      }
      int ans = 0;
      for(int i = 0 ; i<rowsize ; i++){
        int temp = matrix[i][0];
        if(temp==-1){
          continue;
        }
        for(int j = 0 ; j<colsize ; j++){
          
          if(matrix[i][j]==-1){
            break;
          }
          else{
            ans = max(ans,(matrix[i][j]*(j+1)));
          }
        }
      }
      
      return ans;
      
      
      
    }
};