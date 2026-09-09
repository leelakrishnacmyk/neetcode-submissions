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
    int goodNodes(TreeNode* root) {
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,-1e9});
        while(!q.empty()){
            int sz=q.size();
            for (int i=0;i<sz;i++){
                TreeNode*node=q.front().first;
                int prev=q.front().second;
                q.pop();
                if (node->val >= prev){
                    ans.push_back(node->val);
                }
                if (node->left) q.push({node->left,max(prev,node->val)});
                if (node->right) q.push({node->right,max(prev,node->val)});
                
            }
        }
          return ans.size();
    }
};
