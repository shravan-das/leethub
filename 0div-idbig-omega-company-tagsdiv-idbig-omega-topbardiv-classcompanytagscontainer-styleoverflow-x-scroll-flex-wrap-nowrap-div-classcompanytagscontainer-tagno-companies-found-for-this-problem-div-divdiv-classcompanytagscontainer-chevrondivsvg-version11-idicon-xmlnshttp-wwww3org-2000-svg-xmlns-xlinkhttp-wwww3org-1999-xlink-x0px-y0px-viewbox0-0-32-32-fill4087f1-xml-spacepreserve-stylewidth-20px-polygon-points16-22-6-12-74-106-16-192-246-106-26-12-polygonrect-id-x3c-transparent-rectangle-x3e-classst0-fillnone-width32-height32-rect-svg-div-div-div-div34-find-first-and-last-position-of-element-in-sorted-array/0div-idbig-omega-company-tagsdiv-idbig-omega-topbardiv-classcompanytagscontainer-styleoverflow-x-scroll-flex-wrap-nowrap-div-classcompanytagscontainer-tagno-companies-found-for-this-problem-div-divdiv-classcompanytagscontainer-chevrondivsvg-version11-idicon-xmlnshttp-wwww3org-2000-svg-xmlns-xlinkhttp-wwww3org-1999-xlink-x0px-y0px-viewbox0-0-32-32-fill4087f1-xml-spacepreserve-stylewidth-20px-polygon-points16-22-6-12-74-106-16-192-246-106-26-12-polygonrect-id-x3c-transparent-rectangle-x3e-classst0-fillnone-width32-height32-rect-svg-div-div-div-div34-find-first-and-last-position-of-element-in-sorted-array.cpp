class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int n = nums.size();
        int ans = -1;
        int end = n-1;
        vector<int>solution;
        
        
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                ans = mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
        }
        solution.push_back(ans);
        
        start = 0;
        end = n-1;
        ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                ans = mid;
                start = mid+1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
        }
        
        
        solution.push_back(ans);
        return solution;
        
        
        
        
    }   
};