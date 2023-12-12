class Solution {
public:
    int maxProduct(vector<int>& nums) {
      priority_queue<int>pq;
      for(auto it : nums){
        pq.push(it);
      }
      int prod = 1;
      for(int i = 0 ; i<2 ; i++){
        int num = pq.top()-1;
        prod = prod*num;
        pq.pop();
      }
      return prod;
        
    }
};