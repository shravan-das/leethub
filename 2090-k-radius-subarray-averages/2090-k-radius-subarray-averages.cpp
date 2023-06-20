class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
      int n = nums.size();
      if(k==0){
        return nums;
      }
      vector<long long>pre(n,0);
      long long presum = 0;
     
      for(int i = 0 ; i<n ; i++){
        presum = presum+nums[i];
        pre[i] = presum;
      }
      long long i = 0;
      long long j = 2*k;
      long long count = 2*k+1;
      long long temp = 0;
      vector<int>ans(n,-1);
      while(i<k && j<n){
        if(i==0){
          temp = pre[j]/count;
          ans[k] = temp;
          i++;
          j++;
          k++;
          continue;
        }
        
        temp = (long long)((pre[j]-pre[i-1])/count);
        ans[k] = temp;
        k++;
        i++;
        j++;
       
        
        
      }
      return ans;
      
      
      
      
        
    }
};