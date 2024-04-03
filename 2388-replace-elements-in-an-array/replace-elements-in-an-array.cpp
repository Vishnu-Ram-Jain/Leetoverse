class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int i=0;i<n;i++)mp[nums[i]] = i;

        for(auto &i : operations){
            int val = i[0];
            int repVal = i[1];
            int ind = mp[val];
            mp.erase(val);
            nums[ind] = repVal;
            mp[nums[ind]] = ind;
        }
        return nums;
    }
};