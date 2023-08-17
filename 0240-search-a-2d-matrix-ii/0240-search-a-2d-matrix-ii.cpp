class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        int i = 0;
        int j = colsize-1;
        while(i<rowsize && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
        
    }
};