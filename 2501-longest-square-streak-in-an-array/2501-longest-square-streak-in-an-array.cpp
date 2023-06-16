class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
      int n = 100005;
      int maxi = -1;
      set<int>st;
      for(int num : nums){
        st.insert(num);
      }
      sort(nums.begin(),nums.end());
      vector<int>dp(n,1);
      for(int num : nums){
        int sqt = sqrt(num);
        if(sqt*sqt==num && st.find(sqt)!=st.end()){
          dp[num] = dp[sqt]+1;
        }
        maxi = max(maxi,dp[num]);
        
      }
      
      if(maxi==1){
        return -1;
      }
      return maxi;
        
    }
};