class Solution {
public:
    void func(vector<int>&nums , vector<int>&structure , vector<vector<int>>&answer,        vector<int>&mp){
        
        if(structure.size()==nums.size()){
            answer.push_back(structure);
            return;
        }
        
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp[i]==0){
                structure.push_back(nums[i]);
                mp[i]=1;
                func(nums,structure,answer,mp);
                mp[i] = 0;
                structure.pop_back();
                
            }
        }
        
    }
    
        
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>structure;
        vector<vector<int>>answer;
        int n = nums.size();
        vector<int>mp(n,0);
        func(nums,structure,answer,mp);
        return answer;
        
        
    }
};