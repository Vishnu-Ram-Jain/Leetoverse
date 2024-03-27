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
    int dfs(unordered_map<int,int> &mp, int &maxi, TreeNode* root){
        if(root==NULL)return 0;
        // if(root->left==NULL && root->right==NULL){
        //     mp[root->val]++;
        //     maxi = max(maxi,mp[root->val]);
        //     return root->val;
        // }

        int leftsum = dfs(mp,maxi,root->left);
        int rightsum = dfs(mp,maxi,root->right);

        int sum = root->val + leftsum + rightsum;
        mp[sum]++;
        maxi = max(maxi,mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxi = -1e9;
        unordered_map<int,int> mp;
        dfs(mp,maxi,root);
        vector<int> ans;
        for(auto it : mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};