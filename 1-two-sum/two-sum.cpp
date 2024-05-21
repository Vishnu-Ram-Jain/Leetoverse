class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            if(mp.find(target - ele) != mp.end()){
                return {i,mp[target-ele]};
            }
            mp[ele] = i;
        }
        return {};
    }
};