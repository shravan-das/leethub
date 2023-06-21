class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>sol;
        for(int i = 0 ; i<n ; i++){
            if(mp.find(target-nums[i])!=mp.end()){
                sol.push_back(mp[target-nums[i]]);
                sol.push_back(i);
                
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return sol;
        
        
        
        
    }
};