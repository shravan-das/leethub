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
    void inorder(TreeNode* root,map<int,int>& ans){
      if(root==NULL){
        return;
      }
      inorder(root->left,ans);
      ans[root->val]++;
      inorder(root->right,ans);
      
      
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>ans;
        inorder(root,ans);
        vector<int>sol;
        int maxi = INT_MIN;
        for(auto it : ans){
           maxi = max(it.second,maxi);
          }
        for(auto it : ans){
          if(it.second==maxi){
            sol.push_back(it.first);
          }
        }
       return sol;
        }
        
    
};