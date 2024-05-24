class Solution {
public:
    typedef long long ll;
    bool check(vector<int> &nums, ll k, ll mid){
        // vector<int> nums = arr;
        int n = nums.size();
        // int sum = 0;
        for(int i=0;i<n;i++){
            k -= (nums[i]/mid);
            if(k <= 0)return true;
        }
        return 0;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        ll s = 1;
        ll e = 1e14;
        ll ans = -1;
        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum < k)return 0;

        while(s <= e){
            ll mid = s+(e-s)/2;

            if(check(nums,k,mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};