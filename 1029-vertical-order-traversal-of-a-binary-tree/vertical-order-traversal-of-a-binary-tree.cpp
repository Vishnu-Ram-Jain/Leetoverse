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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        // lvl,x-coordinate;
        q.push({root,{0,0}});

        while(!q.empty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                TreeNode* node = q.front().first;
                int col = q.front().second.first;
                int row = q.front().second.second;
                q.pop();
                mp[row][col].push_back(node->val);

                if(node->left!=NULL)q.push({node->left,{col+1,row-1}});
                if(node->right!=NULL)q.push({node->right,{col+1,row+1}});
            }

        }

        vector<vector<int>> ans;
        for(auto &it : mp){
            vector<int> temp;
            for(auto &j : it.second){
                sort(j.second.begin(),j.second.end());
                for(auto i : j.second)temp.push_back(i);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};