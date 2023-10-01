class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        stack<string>st;
        
        
        for(int i = 0 ; i<n ; i++){
            string word = "";
            string word2 = "";
            st.push(" ");
            while(s[i]!=' ' && i<n){
                word = s[i];
                st.push(word);
                i++;
            }
            while(!st.empty()){
                word2 = word2 + st.top();
                st.pop();
            }
            ans = ans + word2;
            
        }
        ans.erase(n);
        return ans;
        
        
        
    }
};