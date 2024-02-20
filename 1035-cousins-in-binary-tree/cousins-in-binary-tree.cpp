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
    queue<TreeNode*> q;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> depth;

    bool isCousins(TreeNode* root, int x, int y) {
        if (root==NULL) return false;

        TreeNode *left=NULL, *right=NULL;

        parent[root]=NULL;
        depth[root]=0;
        q.push(root);

        while (!q.empty()) {
            TreeNode *root = q.front();

            if (root->val==x) left=root;
            else if (root->val==y) right=root;

            if (root->left) {
                q.push(root->left);
                parent[root->left]=root;
                depth[root->left]=depth[root]+1;
            }
            if (root->right) {
                q.push(root->right);
                parent[root->right]=root;
                depth[root->right]=depth[root]+1;
            }
            
            q.pop();

            if (left && right){
                if (parent[left]!=parent[right] && depth[left]==depth[right]) {
                    return true;
                }
            }
        }
        return false;
    }
};