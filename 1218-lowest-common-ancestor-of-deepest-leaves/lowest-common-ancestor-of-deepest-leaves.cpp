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
    TreeNode* f(TreeNode*root, TreeNode*p, TreeNode*q){
        if(root==NULL or root==p or root==q)return root;

        TreeNode* left = f(root->left,p,q);
        TreeNode* right = f(root->right,p,q);

        if(left==NULL)return right;
        else if(right==NULL)return left;
        else return root;
    }
    TreeNode* LOT(TreeNode* root) {
        // vector<vector<TreeNode*>> ans;
        queue<TreeNode*> q;
        q.push(root);
        // if(root==NULL)return {};
        vector<TreeNode*> level;
        while(!q.empty()){
            int size = q.size();

            if(level.size()>0)level.clear();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if(node->left != NULL)q.push(node->left);
                if(node->right != NULL)q.push(node->right);
            }
            // ans.push_back(level);
        }
        if(level.size()==1)return level[0];
        TreeNode* node = level[0];
        for(int i=1;i<level.size();i++){
            node = f(root,node,level[i]);
        }
        return node;
    }   
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return LOT(root);
    }
};