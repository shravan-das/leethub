class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
      queue<int>q;
      int n = arr.size();
      q.push(start);
      set<int>st;
      while(!q.empty()){
        int temp = q.front();
        int left;
        int right;
        q.pop();
        if(arr[temp]<0){
          continue;
        }
        if(arr[temp]==0){
          return true;
        }
        if(temp+arr[temp]<n){
          right = temp+arr[temp];
          q.push(right);
        }
        if(temp-arr[temp]>=0){
          left = temp-arr[temp];
          q.push(left);
        }
        arr[temp] = -arr[temp];
      }
      
      return false;
        
    }
};