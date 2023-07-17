class Solution {
public:
  long long int n;
  long long int sum = 0;
  long long func(string s , char ch){
    long long int count = 0;
    long long int res = 0;
    for(int i = 0 ; i<n ; i++){
      if(s[i]==ch){
        res = res+((count)*(count+1))/2;;
        count = 0;
        
      }
      else{
        count++;
      }
    }
    
      res = res+((count)*(count+1))/2;
    
    
    return res;
  }
  
  long long appealSum(string s) {
      long long int ans = 0;
      n = s.size();
      sum = (n*(n+1))/2;
      for(char ch = 'a';ch<='z';ch++){
        long long temp = func(s,ch);
        long long curr = sum-temp;
        ans = ans+curr;
      }
    
    
    return ans;
      
      
     
    }
};