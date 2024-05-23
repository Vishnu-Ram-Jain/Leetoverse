class Solution {
public:
    int f(vector<int> &nums, int k, int n, int i, unordered_map<int,int> &mp){
        if(i >= n)return 1;
        int pick = 0;
        if(mp[nums[i]-k] == 0 && mp[nums[i]+k] == 0){
            mp[nums[i]]++;
            pick = f(nums,k,n,i+1,mp);
            mp[nums[i]]--;
        }
        int notpick = f(nums,k,n,i+1,mp);
        return pick + notpick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        return f(nums,k,n,0,mp)-1;
    }
};