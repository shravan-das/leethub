class Solution {
public:
    int uniqueLetterString(string s) {
      map<char,vector<int>>mp;
      set<char>st;
      int n = s.size();
      for(int i = 0 ; i<n ; i++){
        char ch = s[i];
        if(st.find(ch)==st.end()){
          mp[ch].push_back(-1);
        }
        mp[ch].push_back(i);
        st.insert(ch);
      }
      for(char ch = 'A' ; ch<='Z';ch++){
        if(st.find(ch)!=st.end()){
          mp[ch].push_back(n);
        }
      }
      int ans = 0;
      for(auto it : mp){
        char ch = it.first;
        int sol = 0;
        vector<int>temp = it.second;
        for(int i = 1 ; i<temp.size()-1 ; i++){
          if(temp[i]==-1 or temp[i]==n){
            continue;
          }
          sol = sol + (temp[i]-temp[i-1])*(temp[i+1]-temp[i]);
        }
        
        ans = ans+sol;
        
      }
      
      return ans;
        
    }
};