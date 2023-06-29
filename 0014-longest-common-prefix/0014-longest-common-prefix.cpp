class Solution {
  
public:
struct Node {
  Node* links[26];
  bool flag = false;
  int commonprefix = 1;
  string commonword;
};
   bool contains(Node* root ,char ch){
    if(root->links[ch-'a']==NULL){
      return false;
    }
    return true;
  }
  void addnew(char ch,Node* root , Node* temp){
    root->links[ch-'a'] = temp;
    temp->commonprefix = 1;
    temp->commonword = root->commonword+ch;
  }
  void existing(char ch , Node* temp){
    temp->commonprefix = temp->commonprefix+1;
  }
  Node* next(Node* root , char ch){
    return root->links[ch-'a'];
  }
  int func1(Node* temp){
    return temp->commonprefix;
  }
  string func2(Node* temp){
    return temp->commonword;
  }
  void setend(Node* root){
    root->flag = true;
  }
    string longestCommonPrefix(vector<string>& strs){
      int n = strs.size();
      if(n==1){
        return strs[0];
      }
      Node* root = new Node();
      string ans;
      int curr = 0;
      int maxi = 1;
      for(int i = 0 ; i<n ; i++){
        string word = strs[i];
        Node* current = root;
        for(int k = 0 ; k<word.size();k++){
          if(contains(current,word[k])==false){
            addnew(word[k],current,new Node());
            current = next(current,word[k]);
          }
          else if(contains(current,word[k])==true){
            Node* temp = next(current,word[k]);
            existing(word[k],temp);
            curr = func1(temp);
            if(curr==n){
              ans =  func2(temp);
              maxi = curr;
            }
           
            current = next(current,word[k]);
            
          }
        }
        setend(current);
      }
      return ans;
  }
};