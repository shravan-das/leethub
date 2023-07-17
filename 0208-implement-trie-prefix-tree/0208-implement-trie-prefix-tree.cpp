struct Node
    {
        Node *links[26];
        bool flag = false;

        bool contain(char ch)
        {
            if (links[ch - 'a'] == NULL)
            {
                return false;
            }
            return true;
        }

        void insert(char ch, Node *temp)
        {
            links[ch - 'a'] = temp;
        }
        Node* nex(char ch)
        {
            return links[ch - 'a'];
        }
        bool isfinish()
        {
            if (flag == true)
            {
                return true;
            }
            return false;
        }

       void setEnd(){
         flag = true;
       }
     
    };



class Trie
{
    

    private: Node * root;
    public:

        Trie()
        {
            root = new Node();
        }

    void insert(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if ( node->contain(word[i]) == false)
            {
              Node* temp = new Node();
                node->insert(word[i], temp);
            }
            
            node = node->nex(word[i]);
            
        }
       
        node->setEnd();
        
    }
  

    bool search(string word)
    { 
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if ( !node->contain(word[i]))
            {
                return false;
            }
            
            node = node->nex(word[i]);
            
        }
        if( node->isfinish()==true){
          return true;
        }
        return false;;
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->contain(prefix[i]))
            {
                return false;
            }
          node = node->nex(prefix[i]);
        }
        return true;
    }
};
  


/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */