class Solution {
public:
  vector<int>prime;
  
  void sieve(int left ,int right){
    vector<bool>isprime(right+1,false);
    isprime[1] = true;
   
      
    for(long long i = 2 ; i<=right ; i++){
      if(isprime[i]==true){
        continue;
      }
      for(long long k = i*i ; k<=right ; k = k+i){
        isprime[k] = true;
      }
    }
    
   
    
    for(int i = left ; i<=right; i++){
      if(isprime[i]==false){
        prime.push_back(i);
      }
    }
  }
  
  
  
   
  
    vector<int> closestPrimes(int left, int right){
      
      vector<int>ans;
      ans.push_back(-1);
      ans.push_back(-1);
      sieve(left,right);
      if(prime.size()==1 or prime.size()==0){
        return ans;
      }
      int mind = INT_MAX;
      for(int i = 1 ; i<prime.size(); i++){
        if(prime[i]-prime[i-1]<mind){
          mind = prime[i]-prime[i-1];
          ans[0] = prime[i-1];
          ans[1] = prime[i];
        }
      }
      
      return ans;
      
        
    }
};