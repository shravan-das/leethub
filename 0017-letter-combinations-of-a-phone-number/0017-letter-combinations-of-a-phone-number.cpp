class Solution {
public:
  int num;
  int index;
    void helper(string digits , vector<string>key , vector<string>&ans , int i , string temp){
      if(i==digits.size()){
        ans.push_back(temp);
        return;
      } 
      
      for(char ch : key[digits[i]-'0']){
        helper(digits,key,ans,i+1,temp+ch);
      }
    }
  
  
    vector<string> letterCombinations(string digits) {
      vector<string>key = {"#","#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      vector<string>ans;
      string temp ="";
      if(digits == ""){
        return ans;
      }
      helper(digits,key,ans,0,temp);
      return ans;
      
      
    }
};