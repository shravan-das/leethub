class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestsum = INT_MAX;
        int n = nums.size();
        int ans = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<n ; i++){
          int first = nums[i];
          int j = i+1;
          int k = n-1;
          while(j<k){
            if(first+nums[j]+nums[k]==target){
              return target;
            }
            else if(abs(first+nums[j]+nums[k]-target)<closestsum){
              closestsum = abs(first + nums[j] + nums[k] - target);
              ans = first + nums[j] + nums[k];   
               
              
          }
          if(first+nums[j]+nums[k]>target){
            k--;
          }
            else{
              j++;
            }
          
        }
    
    }
      return ans;
    }   
};