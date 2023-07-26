class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int pref = 1;
      int ans = INT_MIN;
      int suff = 1;
      int n = nums.size();
      for(int i = 0 ; i<n ; i++){
        pref = pref*nums[i];
        suff = suff*nums[n-i-1];
        int temp = max(pref,suff);
        ans = max(ans,temp);
        if(pref==0){
          pref = 1;
        }
        if(suff==0){
          suff = 1;
        }
      
      }
      return ans;
      
        
    }
};