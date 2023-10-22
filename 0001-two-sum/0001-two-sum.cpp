class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int sum = 0;
        int k = target;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int rem = k - nums[i];
            if(mp.find(rem) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[rem]);
                break;
            }
            mp[nums[i]] = i;
        }
    
        return ans;
    }
};