class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int ind = abs(nums[i]) - 1;
            if(nums[ind] < 0)v.push_back(ind + 1);
            nums[ind] = -nums[ind];
        }
        return v;
    }
};