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

            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        markParents(root,mp);
        unordered_map<TreeNode*,bool> vis;

        queue<TreeNode*> q;
        q.push(tar);
        vis[tar] = 1;
        int dis = 0;
        while(!q.empty()){
            int size = q.size();
            if(dis == k)break;
            dis++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};