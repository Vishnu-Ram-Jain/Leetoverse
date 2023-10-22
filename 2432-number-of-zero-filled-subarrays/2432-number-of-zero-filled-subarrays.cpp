class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        ll i = 0,j = 0,ans = 0;
        ll cnt = 0;
        for(j = 0;j<n;j++){
            if(nums[j] == 0)cnt++;
            else cnt = 0;

            ans += cnt;
            
        }
        return ans;

    }
};