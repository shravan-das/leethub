class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int>nums;
        int n = num.length();
        vector<int>freq(n,1);
         stack<int>st;
        st.push(0);
        for(int i = 1 ; i<n ; i++){
         if(!st.empty()){
             if(num[st.top()]==num[i]){
                 freq[i] = freq[st.top()] + 1;
             }
         }
            st.push(i);
            if(freq[st.top()]==3){
                int temp = num[st.top()] - '0';
                nums.push_back(temp);
            }
        }
        
        string ans = "";
        int m = nums.size();
        sort(nums.begin() , nums.end());
        int temp;
        if(m>0){
        temp = nums[m-1];
         
        string cat = to_string(temp);
        for(int i = 0; i<3 ; i++){
            ans+= cat;
        }
    }     
        return ans;
        
    }
};