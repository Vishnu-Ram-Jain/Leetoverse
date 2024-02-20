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
    int decimal(int num){
        int i=0;
        int sum = 0;
        while(num!=0){
            int dig = num % 10;
            num = num/10;
            sum += dig * pow(2,i);
            i++;
        }
        return sum;
    }
    void f(TreeNode* root, int &sum, string &op){
        if(root->left==NULL and root->right==NULL){
            op.push_back(root->val+'0');
            // int n = stoi(op);
            // int num = decimal(n);
            sum+= stoi(op,0,2);
            op.pop_back();
            return ;
        }
        op.push_back(root->val+'0');
        if(root->left!= NULL)f(root->left,sum,op);  
        if(root->right!= NULL)f(root->right,sum,op);
        op.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string op;
        int sum = 0;
        f(root,sum,op);
        return sum;
    }
};