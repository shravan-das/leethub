class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      map<char,int>mp;
      for(int i = 0 ; i<magazine.size() ; i++){
        mp[magazine[i]]++;
      }
      
      int n = ransomNote.size();
      
      for(int i = 0 ; i<n ; i++){
        if(mp.find(ransomNote[i])==mp.end()){
          return false;
        }
        else if(mp.find(ransomNote[i])!=mp.end()){
          mp[ransomNote[i]]--;
        }
        if(mp[ransomNote[i]]==0){
          mp.erase(ransomNote[i]);
        }
        
      }
      
      return true;
        
    }
};