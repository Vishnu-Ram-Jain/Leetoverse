class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> v(n,0);

        int maxi = *max_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(k+nums[i] >= maxi)v[i] = true;
        }
        return v;
    }
};