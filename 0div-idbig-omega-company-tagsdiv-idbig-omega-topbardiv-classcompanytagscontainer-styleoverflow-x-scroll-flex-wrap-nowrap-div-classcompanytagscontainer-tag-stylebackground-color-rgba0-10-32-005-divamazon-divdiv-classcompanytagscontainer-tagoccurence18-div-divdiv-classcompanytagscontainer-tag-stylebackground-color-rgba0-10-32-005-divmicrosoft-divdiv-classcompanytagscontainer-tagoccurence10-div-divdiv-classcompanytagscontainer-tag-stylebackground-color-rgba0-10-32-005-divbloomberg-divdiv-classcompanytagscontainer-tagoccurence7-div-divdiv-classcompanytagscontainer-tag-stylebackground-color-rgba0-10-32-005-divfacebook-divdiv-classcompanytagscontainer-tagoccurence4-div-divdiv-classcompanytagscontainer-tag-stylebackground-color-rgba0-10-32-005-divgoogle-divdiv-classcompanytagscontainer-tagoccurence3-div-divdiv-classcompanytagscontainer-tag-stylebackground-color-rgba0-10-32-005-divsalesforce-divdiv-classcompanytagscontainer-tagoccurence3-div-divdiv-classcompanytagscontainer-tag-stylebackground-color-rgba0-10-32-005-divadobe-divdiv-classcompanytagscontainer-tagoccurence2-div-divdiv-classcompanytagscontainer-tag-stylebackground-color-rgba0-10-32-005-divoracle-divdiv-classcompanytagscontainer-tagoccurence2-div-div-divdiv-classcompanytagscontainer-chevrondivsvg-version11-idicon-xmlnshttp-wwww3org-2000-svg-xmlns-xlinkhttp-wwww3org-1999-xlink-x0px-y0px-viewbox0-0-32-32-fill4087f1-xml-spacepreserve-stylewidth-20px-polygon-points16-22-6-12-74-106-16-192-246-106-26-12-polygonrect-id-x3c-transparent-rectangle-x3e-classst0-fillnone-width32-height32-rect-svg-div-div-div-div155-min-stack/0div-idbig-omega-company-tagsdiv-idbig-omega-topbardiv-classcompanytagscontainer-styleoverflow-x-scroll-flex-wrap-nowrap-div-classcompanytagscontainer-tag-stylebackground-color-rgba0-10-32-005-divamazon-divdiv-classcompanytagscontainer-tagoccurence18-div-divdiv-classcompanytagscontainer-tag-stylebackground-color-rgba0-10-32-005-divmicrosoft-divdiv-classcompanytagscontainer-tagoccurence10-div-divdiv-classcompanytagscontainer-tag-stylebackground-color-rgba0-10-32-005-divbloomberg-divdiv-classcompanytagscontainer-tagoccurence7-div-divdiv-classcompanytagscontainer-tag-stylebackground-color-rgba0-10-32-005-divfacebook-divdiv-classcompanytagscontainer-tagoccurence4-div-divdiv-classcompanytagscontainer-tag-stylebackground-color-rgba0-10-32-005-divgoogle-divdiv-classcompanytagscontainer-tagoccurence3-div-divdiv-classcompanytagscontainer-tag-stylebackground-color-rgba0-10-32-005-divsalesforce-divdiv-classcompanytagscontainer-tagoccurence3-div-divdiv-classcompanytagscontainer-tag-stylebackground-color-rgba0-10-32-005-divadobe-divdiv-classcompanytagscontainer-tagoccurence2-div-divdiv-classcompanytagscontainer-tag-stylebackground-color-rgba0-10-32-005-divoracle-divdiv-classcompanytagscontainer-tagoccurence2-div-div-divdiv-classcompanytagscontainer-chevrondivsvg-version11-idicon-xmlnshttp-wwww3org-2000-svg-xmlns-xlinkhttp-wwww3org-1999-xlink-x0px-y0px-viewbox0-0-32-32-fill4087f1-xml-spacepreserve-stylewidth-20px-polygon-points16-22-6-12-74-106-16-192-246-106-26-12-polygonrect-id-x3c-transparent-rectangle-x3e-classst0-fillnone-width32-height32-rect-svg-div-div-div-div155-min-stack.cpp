class MinStack {
public:
    vector<pair<int,int>>mp;
    MinStack() {
     
        
    }
    
    void push(int val) {
      if(mp.size()==0){
        mp.push_back({val,val});
      }
      else{
        pair<int,int>temp;
        temp.first = val;
        temp.second = min(val,mp.back().second);
        mp.push_back(temp);
      }
        
    }
    
    void pop() {
        mp.pop_back();
    }
    
    int top() {
        int temp = mp.back().first;
        return temp;
    }
    
    int getMin() {
      int temp = mp.back().second;
      return temp;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */