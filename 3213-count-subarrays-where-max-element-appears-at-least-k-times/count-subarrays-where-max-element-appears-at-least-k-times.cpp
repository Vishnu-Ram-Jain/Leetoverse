class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        ll maxi = *max_element(nums.begin(),nums.end());

        int i=0,j=0,end=n-1;;
        ll cnt = 0;
        for(j=0;j<n;j++){
            if(nums[j] == maxi)cnt++;

            while(cnt == k){
                ans += (end-j+1);
                if(nums[i] == maxi)cnt--;
                i++;
            }
        }
        return ans;
    }
};