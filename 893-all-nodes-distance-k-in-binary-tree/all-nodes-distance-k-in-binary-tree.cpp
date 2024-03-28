/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right!=NULL){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // if(root->left==NULL and root->right==NULL)return 
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> mp;
        markParents(root,mp);
        unordered_map<TreeNode*,bool> vis;
        vector<int> ans;
        vis[target] = 1;
        q.push(target);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            if(level == k)break;
            level++;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL && !vis[node->left]){
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right!=NULL && !vis[node->right]){
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(mp[node] &&!vis[mp[node]]){
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};