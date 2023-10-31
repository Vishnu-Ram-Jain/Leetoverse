class Solution {
public:
    // int f(vector<int> &nums, int k){
    //     int i = 0, j = 0, ans = INT_MAX, sum = 0;
    //     int n = nums.size();
    //     for(j = 0;j<2*n;j++){
    //         sum += nums[j%n];

    //         while(sum > k){
    //             sum -= nums[i%n];
    //             i++;
    //         }
            
    //         if(sum == k)ans = min(ans,(j-i+1));
    //     }
    //     return ans;
    // }
    typedef long long ll;
    int minSizeSubarray(vector<int>& nums, int target) {
        ll ans = INT_MAX, j = 0, csum = 0, n = nums.size();
        ll sum = 0;
        // sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0;i<n;i++)sum += nums[i];

        if(target > sum ) {
            ll sz = target / sum;
            ll rem = target % sum;
            if(rem == 0) return n*sz;
            ans = n * sz;
            csum = sum * sz;
            ll cdiff = INT_MAX;
            for(int i=0;i<2*n;i++) {
                csum += nums[i%n];
                while(csum > target) csum -= nums[j%n], j++;
                if(csum == target) cdiff = min(cdiff, i-j+1);
            }
            if(cdiff == INT_MAX) return -1;
            return ans + cdiff;
        } 
        else {
            for(int i=0;i<2*n;i++) {
                csum += nums[i%n];
                if(csum == target) ans = min(ans, i-j+1);
                while(csum > target) csum -= nums[j%n], j++;

                if(csum == target) ans = min(ans, i-j+1);
            }
        }
        return ans > 1e9 ? -1 : ans;
    }
};