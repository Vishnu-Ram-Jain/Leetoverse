class Solution {
public:
    typedef long long ll;
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        ll i = 0,j = 0, ans = 0, cnt = 0;
        int n = nums.size();
        for(j=0;j<n;j++){
            cnt += mp[nums[j]];
            mp[nums[j]]++;

            while(i < j && cnt >= k){
                ans += n - j;
                mp[nums[i]]--;
                cnt -= mp[nums[i]];
                i++;
            }
        }
        return ans;
    }
};