class Solution {
public:
    vector<int> countBits(int n) {
        
       vector<int>ans(n+1);
       ans[0] = 0;
       int power = 1;
       int nexpower;
        for(int i = 1 ; i<=n ; i++ ){
            if(i!=1 && 2*power==i){
                power = 2*power;
                ans[i] = 1+ans[power-i];
                continue;
            }
            ans[i] = 1+ans[i-power];
        }

        return ans;
    }
};