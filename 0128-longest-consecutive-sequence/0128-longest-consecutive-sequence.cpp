class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>hashset;
        
        for(int num : nums){
            hashset.insert(num);
        }
        
        int longeststreak = 0;
        for(int num : hashset){
            if(!hashset.count(num-1)){
                int currentnumber = num;
                int currentstreak = 1;
                
                
                while(hashset.count(currentnumber+1)){
                    currentnumber += 1;
                    currentstreak += 1;
                }
                
                longeststreak = max(longeststreak , currentstreak);
            }
                
        }
        
        return longeststreak;
        
    }
};