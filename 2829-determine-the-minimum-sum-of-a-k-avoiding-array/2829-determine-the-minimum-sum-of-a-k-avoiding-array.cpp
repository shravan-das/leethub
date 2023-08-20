class Solution {
public:
    int minimumSum(int n, int k) {
      map<int,int>mp;
      int sum = 0;
      int counter = 0;
      for(int i = 1 ; i<=100 ; i++){
        if(counter==n){
          break;
        }
        if(mp.find(k-i)!=mp.end()){
          continue;
        }
        else if(mp.find(k-i)==mp.end()){
          sum = sum+i;
          mp[i] = 1;
          counter++;
        }
      }
      
      return sum;
        
    }
};