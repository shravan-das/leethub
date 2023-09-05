class Solution {
public:
    int minSwaps(vector<int>& nums) {
      int n = nums.size();
      int count_1 = 0;
      for(int i = 0 ; i<n ; i++){
        if(nums[i]==1){
          count_1++;
        }
        nums.push_back(nums[i]);
      }
      int count_0 = 0;
      for(int i = 0 ; i<count_1 ; i++){
        if(nums[i]==0){
          count_0++;
        }
      }
      int ans = count_0;
      int low = 1;
      int high = count_1;
      while(low<n){
        if(nums[low-1]==0){
          count_0--;
        }
        if(nums[high]==0){
          count_0++;
        }
        ans = min(ans,count_0);
        low++;
        high++;
      }
      
      return ans;
        
    }
};