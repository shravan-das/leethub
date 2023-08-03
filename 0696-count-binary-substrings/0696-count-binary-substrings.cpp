class Solution {
public:
    int countBinarySubstrings(string s){
      int curr = 0;
      int prev = 0;
      int count = 1;
      int ans = 0;
      bool flag = false;
      int n = s.size();
      for(int i = 1 ; i<n ; i++){
        if(s[i]==s[i-1]){
          count++;
        }
        else if(s[i]!=s[i-1] && flag==false){
          prev = count;
          count = 1;
          flag = true;
          
        }
        else if(s[i]!=s[i-1] && flag==true){
          ans = ans+min(prev,count);
          prev = count;
          count = 1;
        }
      }
      
      ans = ans+min(prev,count);
      
      
      return ans;

    }
     
   };