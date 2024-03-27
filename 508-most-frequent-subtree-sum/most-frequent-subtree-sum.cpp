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
    int f(TreeNode* root, unordered_map<int,int> &mp, int &maxi){
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            maxi = max(maxi,mp[root->val]);
            return root->val;
        }

        int leftsum = 0;
        if(root->left != NULL){
            leftsum = f(root->left,mp,maxi);
        }
        int rightsum = 0;
        if(root->right != NULL){
            rightsum = f(root->right,mp,maxi);
        }

        int sum = root->val + leftsum + rightsum;
        mp[sum]++;
        maxi = max(maxi,mp[sum]);
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxi = -1e9;
        f(root,mp,maxi);

        vector<int> ans;
        for(auto it : mp){
            if(maxi == it.second)ans.push_back(it.first);
        }
        return ans;
    }
};