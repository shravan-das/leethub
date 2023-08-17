class Solution {
public:
  
  void clearstack(stack<int>&st){
    while(!st.empty()){
      st.pop();
    }
  }
   
void left(vector<int>&temp,vector<int>nums,stack<int>st,bool flag){
   int n = nums.size();
   for(int i = 1 ; i<n ; i++){
     while(!st.empty()){
       if(flag==false && nums[st.top()]<=nums[i]){
         st.pop();
       }
       else if(flag==true && nums[st.top()]>=nums[i]){
         st.pop();
       }
       else{
         break;
       }
     }
     if(st.empty()){
       temp[i] = 0;
     }
     else{
       temp[i] = st.top()+1;
     }
     st.push(i);
   }
 }
  
void right(vector<int>&temp,vector<int>nums,stack<int>st,bool flag){
   int n = nums.size();
   for(int i = n-2 ; i>=0 ; i--){
     while(!st.empty()){
       if(flag==false && nums[st.top()]<nums[i]){
         st.pop();
       }
       else if(flag==true && nums[st.top()]>nums[i]){
         st.pop();
       }
       else{
         break;
       }
     }
     if(st.empty()){
       temp[i] = n-1;
     }
     else{
       temp[i] = st.top()-1;
     }
     st.push(i);
   }
 }
   
   
  
    long long subArrayRanges(vector<int>& nums){
      int n = nums.size();
      vector<int>prevsmall(n,0);
      vector<int>nexsmall(n,n-1);
      vector<int>nexg(n,n-1);
      vector<int>prevg(n,0);
      stack<int>st;
      st.push(0);
      left(prevsmall,nums,st,true);
      clearstack(st);
      st.push(0);
      left(prevg,nums,st,false);
      clearstack(st);
      st.push(n-1);
      right(nexsmall,nums,st,true);
      clearstack(st);
      st.push(n-1);
      right(nexg,nums,st,false);
      clearstack(st);
      long long sum = 0;
      for(int i = 0 ; i<n ; i++){
        long long smallcontri = (long long)(i-prevsmall[i]+1)*(long long)(nexsmall[i]-i+1);
        long long greatcontri = (i-prevg[i]+1)*(nexg[i]-i+1);
        sum = sum + (long long)(nums[i]*greatcontri-nums[i]*smallcontri);
      }
      
      return sum;
      
      
      
      
      
      
      
        
    }
};