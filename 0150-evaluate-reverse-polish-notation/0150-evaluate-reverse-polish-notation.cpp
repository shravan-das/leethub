class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<string>st;
      int n = tokens.size();
      for(int i = 0 ; i<tokens.size() ; i++){
        if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
          string temp = st.top();
          int num1 = stoi(temp);
          st.pop();
          string temp2 = st.top();
          int num2 = stoi(temp2);
          st.pop();
          int ans;
          if(tokens[i]=="+"){
            ans = num2+num1;
          }
          else if(tokens[i]=="-"){
            ans = num2-num1;
          }
          else if(tokens[i]=="*"){
            ans = num1*num2;
          }
          else{
            ans = num2/num1;
          }
          string curr = to_string(ans);
          st.push(curr);
          
          
        }
        else{
          st.push(tokens[i]);
        }
      }
      int finans = stoi(st.top());
      return finans;
        
    }
};