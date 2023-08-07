class Solution {
public:
   int maximalarea(vector<int>nums){
     int n = nums.size();
     vector<int>left(n);
     vector<int>right(n);
     stack<int>st;
     int el;
     for(int i = 0 ; i<n ; i++){
       while(!st.empty() && nums[st.top()]>=nums[i]){
         st.pop();
       }
       if(st.size()==0){
         left[i] = 0;
       }
       else{
         left[i] = st.top()+1;
       }
       st.push(i);
       
     }
     while(!st.empty()){
       st.pop();
     }
     
     for(int i = n-1 ; i>=0 ; i--){
       while(!st.empty() && nums[st.top()]>=nums[i]){
         st.pop();
       }
       if(st.size()==0){
         right[i] = n-1;
       }
       else{
         right[i] = st.top()-1;
       }
       st.push(i);
     }
     int maxarea = 0;
     for(int i = 0 ; i<n ; i++){
       maxarea = max(maxarea,(right[i]-left[i]+1)*nums[i]);
     }
     return maxarea;
     
   }
  
    int maximalRectangle(vector<vector<char>>& matrix) {
      int rowsize = matrix.size();
      int colsize = matrix[0].size();
      int maxans = 0;
      vector<int>temp(colsize,0);
      for(int i = 0 ; i<rowsize ; i++){
        for(int j = 0 ; j<colsize ;j++){
          if(matrix[i][j]=='1'){
            temp[j] = temp[j]+1;
          }
          else{
            temp[j] = 0;
          }
        }
        int tempans = maximalarea(temp);
        maxans = max(maxans,tempans);
      }
      
      return maxans;
        
    }
};