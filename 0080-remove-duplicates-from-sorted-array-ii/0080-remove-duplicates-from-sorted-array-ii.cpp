class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int j = 1;
      int n = nums.size();
      for(int i = 1 ; i<n ; i++){
        if(i==1 or nums[j-2]!=nums[i]){
          nums[j] = nums[i];
          j++;
        }
      }
      
      return j;
        
    }
};