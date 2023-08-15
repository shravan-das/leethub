class Solution {
public:
    int sumSubarrayMins(vector<int>& arr){
      int n = arr.size();
      vector<int>left(n,-1);
      vector<int>right(n,-1);
      stack<int>st;
      for(int i = 0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
          left[i] = left[st.top()];
          st.pop();
        }
        if(left[i]==-1){
          left[i] = i;
        }
        st.push(i);
      }
      while(!st.empty())st.pop();
      
      for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && arr[st.top()]>arr[i]){
          right[i] = right[st.top()];
          st.pop();
        }
        if(right[i]==-1){
          right[i] = i;
        }
        st.push(i);
      }
      
      long sum = 0;
      int mod = 1e9+7;
      for(int i = 0 ; i<n ; i++){
        sum = (sum + ((i-left[i]+1)*(right[i]-i+1))*long(arr[i]))%mod;
        sum = sum%mod;
      }
      return sum;
      
        
    }
};