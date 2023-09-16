class Solution {
public:
    int countBattleships(vector<vector<char>>& board){
      int count = 0;
      int top = 0;
      int left = 0;
      int rowsize = board.size();
      int colsize = board[0].size();
      for(int i = 0 ; i<rowsize ; i++){
        for(int j = 0 ; j<colsize ; j++){
          top = i-1;
          left = j-1;
          if(board[i][j]=='X' && (i==0 or board[top][j]=='.') && (j==0 or board[i][left]=='.')){
            count++;
          }
        }
      }
      
      return count;
        
    }
};