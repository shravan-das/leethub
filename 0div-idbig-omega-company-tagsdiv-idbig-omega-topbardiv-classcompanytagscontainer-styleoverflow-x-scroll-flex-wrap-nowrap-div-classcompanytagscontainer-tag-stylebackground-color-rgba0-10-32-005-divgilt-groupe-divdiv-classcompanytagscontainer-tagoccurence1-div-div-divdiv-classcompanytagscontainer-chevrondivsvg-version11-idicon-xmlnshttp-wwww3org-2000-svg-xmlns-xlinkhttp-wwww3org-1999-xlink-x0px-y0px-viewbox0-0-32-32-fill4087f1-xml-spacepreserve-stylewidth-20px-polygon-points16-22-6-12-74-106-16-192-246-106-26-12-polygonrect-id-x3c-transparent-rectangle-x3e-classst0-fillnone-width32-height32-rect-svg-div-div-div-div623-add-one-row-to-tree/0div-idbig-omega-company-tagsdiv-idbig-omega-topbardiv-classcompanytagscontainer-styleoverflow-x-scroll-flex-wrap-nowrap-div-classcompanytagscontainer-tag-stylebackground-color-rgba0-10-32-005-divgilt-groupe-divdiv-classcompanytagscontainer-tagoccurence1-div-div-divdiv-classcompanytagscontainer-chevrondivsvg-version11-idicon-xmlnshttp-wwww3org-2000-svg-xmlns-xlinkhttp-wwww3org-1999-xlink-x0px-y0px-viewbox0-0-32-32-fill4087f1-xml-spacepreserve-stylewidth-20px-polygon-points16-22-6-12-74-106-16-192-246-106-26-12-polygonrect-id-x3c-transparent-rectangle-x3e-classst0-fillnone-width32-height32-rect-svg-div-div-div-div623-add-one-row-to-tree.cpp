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
     void func(TreeNode* root , int val , int depth){
       queue<pair<int,TreeNode*>>q;
       q.push({1,root});
       bool flag = false;
       
       while(!q.empty()){
         int n = q.size();
         for(int i = 0 ; i<n ; i++){
           TreeNode* node = q.front().second;
           int level = q.front().first;
           TreeNode* l = NULL;
           TreeNode* r = NULL;
           q.pop();
           if(level==depth-1){
             if(node->left){
               l = node->left;
             }
             if(node->right){
               r = node->right;
             }
             TreeNode* newnodel = new TreeNode(val);
             TreeNode* newnoder = new TreeNode(val);
             node->left = newnodel;
             node->right = newnoder;
             newnodel->left = l;
             newnoder->right = r;
             flag = true;
             continue;
          }
           if(node->left){
             q.push({level+1,node->left});
           }
           if(node->right){
             q.push({level+1,node->right});
           }
           
           
         }
         if(flag==true){
           break;
          }
         
        }
       
      }
  
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      if(depth==0){
        return root;
      }
      if(depth==1){
        TreeNode* newnode = new TreeNode(val);
        newnode->left = root;
        return newnode;
      }
      func(root,val,depth);
      return root;
        
    }
};