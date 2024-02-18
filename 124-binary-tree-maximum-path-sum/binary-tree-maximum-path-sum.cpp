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
    int maxi = INT_MIN;
    int f(TreeNode* root){
        if(root==NULL)return 0;

        int leftsum = max(0,f(root->left));
        int rightsum = max(0,f(root->right));

        maxi = max(maxi,root->val+leftsum+rightsum);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
         f(root);
         return maxi;
    }
};