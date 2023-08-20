class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans;
        int n = words.size();
        for(int i = 0 ; i<n ; i++){
          char ch = words[i][0];
          ans = ans+ch;
        }
      if(ans==s){
        return true;
      }
      return false;
    }
};