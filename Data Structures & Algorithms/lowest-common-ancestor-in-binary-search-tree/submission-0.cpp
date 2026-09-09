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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
      if (root==nullptr){
        return nullptr;
      }
      if (root==p || root==q){
        return root;
      }
       TreeNode* left=solve(root->left,p,q);
       TreeNode* right=solve(root->right,p,q);
       if (left && right){
        return root;
       }
       if(left){
         return left;
       }
       if (right){
        return  right;
       }
       return nullptr;
    }
};
