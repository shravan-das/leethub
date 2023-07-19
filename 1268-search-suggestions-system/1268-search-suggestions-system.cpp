class Solution {
  struct Node{
    Node* links[26];
    bool flag = false;
    
    void insert(char ch , Node* temp){
      links[ch-'a'] = temp;
    }
     bool contain(char ch)
        {
            if (links   [ch - 'a'] == NULL)
            {
                return false;
            }
            return true;
        }
    Node* nex(char ch){
      return links[ch-'a'];
    }
    
   
  };
  
public:
   void dfs(vector<string>&result,Node* temp,string prefix){
      if(result.size()==3){
        return;
      }
      if(temp->flag==true){
        result.push_back(prefix);
      }
      for(char Ch = 'a';Ch<='z';Ch++){
        if(temp->links[Ch-'a']!=NULL){
          dfs(result,temp->nex(Ch),prefix+Ch);
        }
      }
      
    }
    
    vector<string> start(string &prefix,Node* temp){
      vector<string>result;
      for(char ch : prefix){
        if(temp->links[ch-'a']==NULL){
          return {};
        }
        
          temp = temp->nex(ch);
      
      }
      
     dfs(result,temp,prefix);
      return result;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      sort(products.begin(),products.end());
      Node *root = new Node();
      Node *node = root;
      vector<vector<string>>ans;
      
      for(int i = 0 ; i<products.size(); i++){
        string word = products[i];
        node = root;
        for(int j = 0 ; j<word.size() ; j++){
          if(node->contain(word[j])==NULL){
            Node *temp = new Node();
            node->insert(word[j],temp);
          }
          node = node->nex(word[j]);
        
        }
        node->flag = true;
      }
      string temp;
      vector<vector<string>>res;
      for(char ch : searchWord){
        temp = temp+ch;
        node = root;
        res.push_back(start(temp,node));
        
      }
      
      return res;
      
      
    }
  
   
      
        
    
};