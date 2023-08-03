class Solution {
public:
    int kthFactor(int n, int k) {
      int ans = -1;
      if(k==1){
        return 1;
      }
      for(int i = 1 ; i<=n ; i++){
        if(k==0){
          break;
        }
        if(n%i==0){
          ans = i;
          k--;
        }
      }
      
      if(k==0){
        return ans;
      }
        return -1;
    }
};