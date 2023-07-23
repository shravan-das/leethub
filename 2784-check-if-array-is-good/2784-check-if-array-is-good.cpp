class Solution {
public:
    bool isGood(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      map<int,int>mp;
      for(int num : nums){
        mp[num]++;
      }
      int n = nums.size();
      int m = n-1;
      int curr = nums[n-1];
      if(mp[curr]>2){
        return false;
      }
      for(int i = 0 ; i<nums.size();i++){
        if(nums[i]!=curr && mp[nums[i]]>1){
          return false;
        }
      }
      if(nums[n-1]==m && nums[n-2]==m && curr==m){
        return true;
      }
      return false;
        
    }
};