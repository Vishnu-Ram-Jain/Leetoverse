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
    typedef long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        // if(root->left==NULL and root->right==NULL)return 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        int maxwidth = 0;
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int first,last;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                ll ind = q.front().second - mini;
                q.pop();

                if(i==0)first = ind;
                if(i==size-1)last = ind;
                
                if(node->left!=NULL)q.push({node->left,2*ind + 1});
                if(node->right!=NULL)q.push({node->right,2*ind + 2});
            }

            maxwidth = max(maxwidth,last-first+1);
        }
        return maxwidth;
    }
};