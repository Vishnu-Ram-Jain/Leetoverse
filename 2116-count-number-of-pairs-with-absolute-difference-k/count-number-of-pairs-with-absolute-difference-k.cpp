class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int val1 = nums[i] + k;
            int val2 = nums[i] - k;
            if(mp.find(val1) != mp.end())cnt += mp[val1];
            if(mp.find(val2) != mp.end())cnt += mp[val2];

            mp[nums[i]]++;
        }
        return cnt;
    }
};