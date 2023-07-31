class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int n = s.size();
      int minflips = 0;
      int nof_1 = 0;
      for(int i = 0 ; i<n ; i++){
        if(s[i] == '1'){
          nof_1++;
        }
        else if(s[i]=='0'){
          minflips = min(minflips+1,nof_1);
        }
      }
      
      return minflips;
    }
};