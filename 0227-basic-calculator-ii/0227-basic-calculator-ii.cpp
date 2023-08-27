class Solution {
public:
    int calculate(string s) {
      int n = s.size();
      char currsign = '+';
      int sign = 1;
      stack<int>st;
      
      for(int i = 0 ; i<n ; i++){
        long long int currnumber = 0;
        char ch = s[i];
        if(isdigit(s[i])){
          while(i<n && isdigit(s[i])){
            currnumber = (currnumber*10)+s[i]-'0';
            i++;
          }
          st.push(currnumber*sign);
          sign = 1;
          i--;
        }
        if(ch=='*'){
          currsign = '*';
        }
        else if(ch=='/'){
          currsign = '/';
        }
        else if(ch=='-'){
          sign = -1*sign;
        }
        else if(currsign=='*' && currnumber!=0){
          st.pop();
          currnumber = st.top()*currnumber;
          currsign = '+';
          st.pop();
          st.push(currnumber);
        }
        else if(currsign=='/' && currnumber!=0){
          st.pop();
          currsign = '+';
          currnumber = st.top()/currnumber;
          st.pop();
          st.push(currnumber);
        }
        
      }
      long long int sum = 0;
      while(!st.empty()){
        sum = sum+st.top();
        st.pop();
      }
      return sum;
        
    }
};