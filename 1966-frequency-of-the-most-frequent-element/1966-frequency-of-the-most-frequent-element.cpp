class Solution {
public:
    typedef long long ll;
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ll i = 0,j = 0,ans = 0,sum = 0;
        for(j = 0;j<n;j++){
            sum += (ll)nums[j];

            while((ll)nums[j] * (ll)(j-i+1) - (ll)sum > (ll)k){
                sum -= (ll)nums[i];
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};