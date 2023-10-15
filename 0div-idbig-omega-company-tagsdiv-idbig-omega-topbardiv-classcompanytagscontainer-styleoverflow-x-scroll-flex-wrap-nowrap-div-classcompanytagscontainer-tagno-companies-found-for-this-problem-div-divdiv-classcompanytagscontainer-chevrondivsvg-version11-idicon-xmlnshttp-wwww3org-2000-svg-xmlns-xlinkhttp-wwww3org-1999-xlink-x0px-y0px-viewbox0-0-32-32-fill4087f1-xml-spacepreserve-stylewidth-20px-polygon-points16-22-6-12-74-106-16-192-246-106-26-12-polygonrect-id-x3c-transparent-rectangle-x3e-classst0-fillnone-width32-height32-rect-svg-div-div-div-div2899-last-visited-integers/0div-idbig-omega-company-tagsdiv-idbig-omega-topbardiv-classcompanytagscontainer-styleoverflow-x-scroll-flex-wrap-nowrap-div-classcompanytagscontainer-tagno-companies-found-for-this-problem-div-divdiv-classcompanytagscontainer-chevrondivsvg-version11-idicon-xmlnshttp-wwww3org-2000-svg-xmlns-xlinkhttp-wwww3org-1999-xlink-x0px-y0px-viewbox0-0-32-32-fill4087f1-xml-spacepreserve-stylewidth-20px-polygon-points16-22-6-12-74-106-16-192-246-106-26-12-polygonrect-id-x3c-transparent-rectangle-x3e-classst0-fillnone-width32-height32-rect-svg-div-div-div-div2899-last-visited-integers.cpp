class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>nums;
        vector<int>ans;
        int n = words.size();
        int k = 0;
        for(int i = 0 ; i<n ; i++){
          if(words[i]!="prev"){
            int t = stoi(words[i]);
            nums.insert(nums.begin(),t);
            k = 0;
          }
          else if(words[i]=="prev"){
            k = k+1;
            if(k<=nums.size()){
              ans.push_back(nums[k-1]);
            }
            else{
              ans.push_back(-1);
            }
            
          }
          
        }
      
      return ans;
    }
};