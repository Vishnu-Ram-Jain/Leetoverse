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
    void solve(TreeNode* root,map<int,int> &mp){
        if(root == NULL)return ;

        solve(root->left,mp);
        mp[root->val]++;
        solve(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        int maxi = 0;
        vector<int> ans;
        solve(root,mp);
        for(auto it : mp){
            maxi = max(maxi,it.second);
        }
        for(auto it : mp){
            if(maxi == it.second)ans.push_back(it.first);
        }
        return ans;

    }
};