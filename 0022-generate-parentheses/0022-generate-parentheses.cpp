class Solution {
public:
   void func(vector<string>& ans,string s , int start , int end , int& n){
     if(start==n && end==n){
       ans.push_back(s);
       return;
     }
     if(start<n){
       func(ans,s + '(' , start+1 , end,n);
     }
     if(end<start && end<n){
       func(ans,s+')',start,end+1,n);
     }
     
     
   }
    vector<string> generateParenthesis(int n) {
      vector<string>ans;
      string s;
      func(ans,s,0,0,n);
      return ans;
      
        
    }
};