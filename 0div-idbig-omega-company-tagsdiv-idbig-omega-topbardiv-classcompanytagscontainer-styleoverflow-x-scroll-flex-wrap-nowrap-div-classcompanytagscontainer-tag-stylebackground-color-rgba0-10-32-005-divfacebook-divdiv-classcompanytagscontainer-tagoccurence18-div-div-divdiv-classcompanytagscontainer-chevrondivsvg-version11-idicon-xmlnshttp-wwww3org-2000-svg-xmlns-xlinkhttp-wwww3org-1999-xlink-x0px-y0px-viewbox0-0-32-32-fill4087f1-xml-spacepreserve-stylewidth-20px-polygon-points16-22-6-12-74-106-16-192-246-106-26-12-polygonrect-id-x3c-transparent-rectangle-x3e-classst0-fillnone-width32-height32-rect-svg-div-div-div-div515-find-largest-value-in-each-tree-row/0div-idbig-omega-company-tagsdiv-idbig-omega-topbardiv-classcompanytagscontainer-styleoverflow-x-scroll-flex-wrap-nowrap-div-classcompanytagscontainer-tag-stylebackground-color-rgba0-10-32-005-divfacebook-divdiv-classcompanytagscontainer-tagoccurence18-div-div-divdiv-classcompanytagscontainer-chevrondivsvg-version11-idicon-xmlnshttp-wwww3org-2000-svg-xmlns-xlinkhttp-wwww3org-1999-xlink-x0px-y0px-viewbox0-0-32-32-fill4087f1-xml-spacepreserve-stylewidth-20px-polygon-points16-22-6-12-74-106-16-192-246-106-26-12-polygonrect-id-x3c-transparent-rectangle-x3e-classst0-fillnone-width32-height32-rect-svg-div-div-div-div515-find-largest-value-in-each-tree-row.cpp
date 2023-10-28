/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
  void func(TreeNode* root , int level , map<int,int>&mp){
    if(root==NULL){
      return;
    }
    if(mp.find(level)==mp.end()){
      mp[level] = root->val;
    }
    else if(mp.find(level)!=mp.end()){
      if(mp[level]<root->val){
        mp[level] = root->val;
      }
    }
    func(root->left,level+1,mp);
    func(root->right,level+1,mp);
  }
    vector<int> largestValues(TreeNode* root) {
      vector<int>ans;
      map<int,int>mp;
      func(root,1,mp);
      for(auto it : mp){
        int temp = it.second;
        ans.push_back(temp);
      }
      
      return ans;
      
        
    }
};