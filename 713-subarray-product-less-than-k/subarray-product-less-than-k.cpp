class Solution {
public:
    typedef long long ll;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)return 0;
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = nums.size();
        int prod = 1;
        for(j = 0;j<n;j++){
            prod *= nums[j];

            while(prod >= k){
                prod /= nums[i];
                i++;
            }
            if(prod < k)ans += (j-i+1);
        }
        return ans ;
    }
};