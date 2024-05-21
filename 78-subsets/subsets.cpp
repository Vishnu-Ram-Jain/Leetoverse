class Solution {
public:
    void f(int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> op){
        if(i >= nums.size()){
            ans.push_back(op);
            return ;
        }

        op.push_back(nums[i]);
        f(i+1,nums,ans,op);
        op.pop_back();
        f(i+1,nums,ans,op);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        f(0,nums,ans,op);
        return ans;
    }
};