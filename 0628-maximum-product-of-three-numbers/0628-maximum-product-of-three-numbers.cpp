class Solution {
public:
    int maximumProduct(vector<int>& nums){
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int num3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
          if(nums[i]<=min1){
             min2 = min1;
             min1 = nums[i];
          }
          else if(nums[i]<=min2){
            min2 = nums[i];
          }
          if(nums[i]>=num1){
            num3 = num2;
            num2 = num1;
            num1 = nums[i];
          }
          else if(nums[i]>=num2){
            num3 = num2;
            num2 = nums[i];
          }
          else if(nums[i]>=num3){
            num3 = nums[i];
          }
        }
      
      int minans = min1*min2*num1;
      int maxans = num1*num2*num3;
      int ans = max(minans,maxans);
      return ans;      
      
      
      
      
      }   
};