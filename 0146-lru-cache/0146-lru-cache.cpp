class LRUCache{
  
   class Node{
     public:
    Node* prev;
    int key;
    int value;
    Node* next;
    Node(int k , int v){
    key = k;
    value = v;
  }
};
  
  int cap;
  Node *head = new Node(-1,-1);
  Node *tail = new Node(-1,-1);
  map<int  , Node*>mp;
public:
    LRUCache(int capacity) {
      cap = capacity;
     
      head->next = tail;
     
      tail->prev = head;
      
    }
  
  void addnode(Node *temp){
    Node *headnex = head->next;
    temp->prev = head;
    temp->next = headnex;
    head->next = temp;
    headnex->prev = temp;
    
  }
  void deletenode(Node *temp){
    Node *tailprev = temp->prev;
    Node *tailnext = temp->next;
    tailprev->next = tailnext;
    tailnext->prev = tailprev;
    
  }
    
    int get(int key) {
      int ans = -1;
      if(mp.find(key)!=mp.end()){
        Node *temp = mp[key];
        ans = temp->value;
        deletenode(temp);
        addnode(temp);
        mp[key] = head->next;
        return ans;
      }
      return ans;
        
    }
    
    void put(int key, int value) {
      if(mp.find(key)!=mp.end()){
       Node *delnode = mp[key];
       deletenode(delnode); 
      }
      else if(mp.find(key)==mp.end() && mp.size()==cap){
        mp.erase(tail->prev->key);
        deletenode(tail->prev);
      }
      
      addnode(new Node(key,value));
      mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */