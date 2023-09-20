class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int sum = 0;
      int n = nums.size();
      for(int it : nums){
        sum = sum + it;
      }
      if(sum==x){
        return n;
      }
      int target = sum-x;
      if(target>sum){
        return -1;
      }
      int currsum = 0;
      int start = 0;
      int ans = 0;
      for(int i = 0 ; i<n ; i++){
        currsum = currsum + nums[i];
        while(start<n && currsum>target){
          currsum = currsum-nums[start];
          start++;
          
        }
        if(currsum==target){
          ans = max(ans,i-start+1);
          
        }
        
      }
      if(ans==0){
        return -1;
      }
      ans = n-ans;
      return ans;
      
        
    }
};