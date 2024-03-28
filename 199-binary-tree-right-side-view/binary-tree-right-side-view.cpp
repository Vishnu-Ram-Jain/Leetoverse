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
    void dfs(TreeNode* root, int lvl, vector<int> &v){
        if(root==NULL)return ;
        if(v.size() == lvl)v.push_back(root->val);
        dfs(root->right,lvl+1,v);
        dfs(root->left,lvl+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        // queue<TreeNode*> q;
        vector<int> v;
        // q.push(root);
        // while(!q.empty()){
        //     int sz = q.size();
        //     vector<int> lvl;
        //     for(int i=0;i<sz;i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(lvl.size() == 0)v.push_back(node->val);
        //         if(node->right!=NULL){
        //             q.push(node->right);
        //         }
        //         if(node->left!=NULL){
        //             q.push(node->left);
        //         }
        //     }
        // }
        dfs(root,0,v);
        return v;
    }
};