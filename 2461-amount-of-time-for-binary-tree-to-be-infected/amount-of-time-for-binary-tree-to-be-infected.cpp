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
    void inorder(TreeNode* root, int st, int &n, TreeNode* &tar){
        if(root==NULL)return;
        if(root->val == st)tar = root;
        n++;
        inorder(root->left,st,n,tar);
        inorder(root->right,st,n,tar);
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root->left==NULL and root->right==NULL)return 0;
        unordered_map<TreeNode*,TreeNode*> mp;
        markParents(root,mp);
        // Parent mark kr dia;
        unordered_map<TreeNode*,bool> vis;
        int totcnt = 0;
        TreeNode* tar = NULL;
        inorder(root,start,totcnt,tar);
        // cout<<tar->val<<" "<<totcnt<<endl;
        // return 0;
        queue<TreeNode*> q;
        q.push(tar);
        vis[tar] = 1;
        int dis = 0;
        int nodecnt = 1;

        while(!q.empty()){
            int size = q.size();
            if(nodecnt == totcnt)break;
            dis++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left] = 1;
                    q.push(node->left);
                    nodecnt++;
                }
                if(node->right && !vis[node->right]){
                    vis[node->right] = 1;
                    q.push(node->right);
                    nodecnt++;
                }
                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                    nodecnt++;
                }
            }
        }
        return dis;
         
    }
};