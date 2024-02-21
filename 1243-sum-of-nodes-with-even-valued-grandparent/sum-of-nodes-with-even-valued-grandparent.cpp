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
    int sum = 0;
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent,
        unordered_map<TreeNode*,TreeNode*> &grandparent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                grandparent[node->left] = parent[parent[node->left]];
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                grandparent[node->right] = parent[parent[node->right]];
                q.push(node->right);
            }
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,TreeNode*> grandparent;
        markParents(root,parent,grandparent);
        // int sum = 0;
        // // cout<<grandparent.size();
        for(auto i : grandparent){
            // if(i.second!=NULL)cout<<i.first->val<<endl;
            if(i.second!=NULL && i.second->val % 2 == 0)sum += i.first->val;
        }
        return sum;
    }
};