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
  int ans = 0;
  void func(TreeNode *root , bool left , int steps){
    ans = max(steps,ans);
    if(root==NULL){
      return;
    }
    if(left==true){
      func(root->left,false,steps+1);
      func(root->right,true,1);
    }
    else if(left==false){
      func(root->right,true,steps+1);
      func(root->left,false,1);
    }
  }
public:
    int longestZigZag(TreeNode* root) {
      func(root,true,0);
      return ans-1;
        
    }
};