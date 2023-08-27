class Solution {
public:
    int calculate(string s) {
      int n = s.size();
      stack<pair<int,int>>st;
      long long int sum = 0;
      int sign = 1;
      for(int i = 0 ; i<n ; i++){
        char ch = s[i];
        if(isdigit(ch)){
        
        long long int num = 0;
        while(i<n && s[i]!='(' && s[i]!=')' && s[i]!='+' && s[i]!='-' && s[i]!= ' ' ){
          num = (num*10)+s[i]-'0';
           i++;
        }
        
        i--;
        
        sum = sum+(num*sign);
        sign = 1;
        }
        else if(ch=='('){
          pair<int,int>p1 = make_pair(sum,sign);
          st.push(p1);
         
          sum = 0;
          sign = 1;
        }
        else if(ch==')'){
          sum = st.top().first+sum*st.top().second;
          
          st.pop();
        }
        else if(ch=='-'){
         
          sign = -1*sign;
        }
        
        
      }
      
      return sum;
      
        
    }
};