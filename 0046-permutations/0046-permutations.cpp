class Solution {
public:
    void f(vector<vector<int>> &ans, int i, vector<int> &nums){
        if(i >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            f(ans,i+1,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        f(ans,0,nums);
        return ans;
    }
};