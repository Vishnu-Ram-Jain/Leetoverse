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
    bool f(TreeNode* root, TreeNode* tarnode, vector<TreeNode*> &ds){
        if(root==NULL)return false;

        ds.push_back(root);
        if(root==tarnode)return true;

        bool l = f(root->left,tarnode,ds);
        bool r = f(root->right,tarnode,ds);

        if(l or r)return true;

        ds.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        f(root,p,v1);
        f(root,q,v2);
        unordered_map<TreeNode*,bool> mp;
        // cout<<v1.size();
        // cout<<v2.size();
        for(auto &i : v1){
            mp[i]=1;
        }
        TreeNode* ans = NULL;
        for(auto i : v2){
            if(mp.find(i) != mp.end()){
                ans = i;
            }
        }
        return ans;
    }
};