class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>map(256,-1);
        int n = s.size();
        int left = 0;
        int right = 0;
        int l = 0;
        
        
        while(right<n){
        if(map[s[right]]!=-1){
            
            left = max(map[s[right]]+1 , left);
            
        }
          map[s[right]] = right;
          l = max(l , right-left+1);
          right++;
            
        
        
        
        }
        
        return l;
        
    }
};