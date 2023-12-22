class Solution {
public:
    int maxScore(string s) {
      int zero_count = 0;
      int one_count = 0;
      int tot = 0;
      int n = s.size();
      for(int i = 0 ; i<n ; i++){
        int temp = s[i] - '0';
        if(temp==1){
          one_count = one_count+1;
        }
      }
      
      int ans = -1;
      for(int i = 0 ; i<n ; i++){
        int num = s[i] - '0';
     
        tot = tot+num;
        if(num==0){
          zero_count = zero_count+1;
        }
        if(zero_count>=1 && one_count-tot>0){
          ans = max(ans,zero_count+(one_count-tot));
        }
       
      }
      if(ans==-1 && one_count>=1 && zero_count>=1){
        return max(one_count-1,zero_count-1);
      }
      if(ans!=-1 && one_count>=1 && zero_count>=1){
        return max(ans,max(one_count-1,zero_count-1));
      }
      if(zero_count==0){
        return one_count-1;
      }
      
        return zero_count-1;

    
      
        
    }
};