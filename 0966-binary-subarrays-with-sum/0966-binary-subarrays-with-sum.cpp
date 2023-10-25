class Solution {
public:
    typedef long long ll;
    int f(vector<int> arr, int k){
        ll i = 0,j = 0, ans = 0, sum = 0;
        int n = arr.size();
        for(j = 0;j<n;j++){
            sum += arr[j];

            while(i <= j && sum > k){
                sum -= arr[i];
                i++;
            }
            // if(sum <= k){
            //     ans += (j-i+1);
            // }
            ans += (j-i+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal) - f(nums,goal - 1);
    }
};