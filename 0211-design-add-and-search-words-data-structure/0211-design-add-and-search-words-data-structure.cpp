class WordDictionary {
  struct Node{
    Node* links[26];
    bool flag = false;
  };
public:
  Node *root = new Node();
    WordDictionary() {
       root = new Node();
        
    }
    
    void addWord(string word) {
      int n = word.size();
      Node* node = root;
      for(int i = 0 ; i<word.size();i++){
        char ch = word[i];
        if(node->links[ch-'a']==NULL){
          Node *temp = new Node();
          node->links[ch-'a'] = temp;
        }
        node = node->links[ch-'a'];
      }
      node->flag = true;
        
    }
  
  bool func(int i,string c , string word,Node* node){
    if(c.size()==word.size()){
      return node->flag;
    }
  
    if(word[i]=='.'){
      for(char ch = 'a';ch<='z';ch++){
        if(node->links[ch-'a']==NULL){
          continue;
        }
        else if(node->links[ch-'a']!=NULL){
          if(func(i+1,c+ch,word,node->links[ch-'a'])==true){
            return true;
          }
         
        }
      }
      return false;
      
    }
    else{
      node = node->links[word[i]-'a'];
      if(node==NULL){
        return false;
      }
      return func(i+1,c+word[i],word,node);
      
    }
    
    
   
   
    
    
    
  }
    
    bool search(string word) {
      Node* node = root ;
      string c;
      return func(0,c,word,node);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */