class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int badi = -1, mini = -1, maxi = -1, n = nums.size();
        ll ans = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > maxK || nums[i] < minK)badi = i;
            if(nums[i] == maxK)maxi = i;
            if(nums[i] == minK)mini = i;

            ans += max(0,min(mini,maxi) - badi);
        }
        return ans;
    }
};