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
    bool incCheck(vector<int> &arr){
        for(auto i : arr){
            if(i % 2 != 1)return false;
        }
        if(arr.size()==1)return true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1] <= arr[i])return false;
        }
        return true;
    }
    bool decCheck(vector<int> &arr){
        for(auto i : arr){
            if(i % 2 != 0)return false;
        }
        if(arr.size()==1)return true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1] >= arr[i])return false;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> lvl;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            if(flag){
                if(incCheck(lvl)==false)return false;
            }
            else{
                if(decCheck(lvl)==false)return false;
            }
            flag = !flag;
        }
        return true;
    }
};