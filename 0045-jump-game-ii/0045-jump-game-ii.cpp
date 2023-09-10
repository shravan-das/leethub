class Solution {
public:
    int jump(vector<int>& nums) {
        int curreach = 0;
        int maxreach = 0;
        int jump = 0;
        int n = nums.size();
        for(int i = 0 ; i<n-1 ; i++){
            maxreach = max(i+nums[i],maxreach);
            if(i==curreach){
                curreach = maxreach;
                jump++;
            }
        }
        return jump;
        
    }
};