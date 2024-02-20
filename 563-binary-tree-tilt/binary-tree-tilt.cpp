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
    int totsum(TreeNode* root){
        if(root==NULL)return 0;

        int leftsum = totsum(root->left);
        int rightsum = totsum(root->right);

        return root->val + leftsum + rightsum;
    }
    int f(TreeNode* root, int &sum){
        if(root==NULL)return 0;

        int leftsum = totsum(root->left);
        int rightsum = totsum(root->right);



        sum += abs(leftsum-rightsum);

        int left = f(root->left,sum);
        int right = f(root->right,sum);


        return root->val;
        // return root->val + left + right;

    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        f(root,sum);
        return sum;
    }
};