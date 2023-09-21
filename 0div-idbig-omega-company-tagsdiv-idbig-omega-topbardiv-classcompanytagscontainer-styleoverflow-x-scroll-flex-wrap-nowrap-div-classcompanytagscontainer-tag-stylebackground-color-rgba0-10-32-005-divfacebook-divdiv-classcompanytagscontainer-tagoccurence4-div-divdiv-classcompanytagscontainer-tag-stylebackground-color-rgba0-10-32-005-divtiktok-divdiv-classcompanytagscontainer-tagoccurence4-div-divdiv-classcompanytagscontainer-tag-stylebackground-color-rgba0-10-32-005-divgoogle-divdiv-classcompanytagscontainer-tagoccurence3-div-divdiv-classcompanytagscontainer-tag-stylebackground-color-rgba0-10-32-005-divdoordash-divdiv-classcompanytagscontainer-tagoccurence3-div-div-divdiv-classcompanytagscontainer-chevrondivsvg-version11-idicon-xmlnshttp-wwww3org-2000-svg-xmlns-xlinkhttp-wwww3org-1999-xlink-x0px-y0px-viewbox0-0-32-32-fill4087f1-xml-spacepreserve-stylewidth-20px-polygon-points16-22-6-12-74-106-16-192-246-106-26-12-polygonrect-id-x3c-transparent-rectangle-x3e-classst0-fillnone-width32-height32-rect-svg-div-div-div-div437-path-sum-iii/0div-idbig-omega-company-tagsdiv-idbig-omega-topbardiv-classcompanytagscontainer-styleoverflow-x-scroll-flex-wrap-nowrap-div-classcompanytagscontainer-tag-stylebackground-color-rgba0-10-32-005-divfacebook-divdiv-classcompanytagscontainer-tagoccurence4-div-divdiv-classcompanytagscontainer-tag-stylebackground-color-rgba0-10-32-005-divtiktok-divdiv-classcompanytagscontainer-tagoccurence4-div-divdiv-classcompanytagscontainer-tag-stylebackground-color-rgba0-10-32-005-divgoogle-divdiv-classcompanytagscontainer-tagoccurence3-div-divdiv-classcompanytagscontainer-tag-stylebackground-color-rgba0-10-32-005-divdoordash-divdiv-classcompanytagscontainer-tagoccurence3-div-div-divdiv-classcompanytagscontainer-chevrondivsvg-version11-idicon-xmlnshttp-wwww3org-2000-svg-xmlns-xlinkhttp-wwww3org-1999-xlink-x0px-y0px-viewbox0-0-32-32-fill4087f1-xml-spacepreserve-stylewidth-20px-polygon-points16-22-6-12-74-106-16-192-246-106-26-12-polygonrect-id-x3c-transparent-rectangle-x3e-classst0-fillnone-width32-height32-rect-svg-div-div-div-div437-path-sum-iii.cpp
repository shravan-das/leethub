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
   int countnum = 0;
   void count(TreeNode *root  ,long long int targetSum){
     
    if(root==NULL){
      return;
    }
    if(root->val==targetSum){
      countnum++;
    } 
    
    count(root->left,targetSum-root->val);
  
    
    count(root->right,targetSum-root->val); 
   
     
    
  }
    int pathSum(TreeNode* root, int targetSum) {
     
      if(root){
      count(root,targetSum);
      pathSum(root->left,targetSum);
      pathSum(root->right,targetSum);
      }
      return countnum;
        
    }
};