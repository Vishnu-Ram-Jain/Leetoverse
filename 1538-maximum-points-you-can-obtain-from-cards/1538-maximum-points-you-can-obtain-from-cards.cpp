class Solution {
public:
    typedef long long ll;
    int f(vector<int> &nums, int k){
        int n = nums.size();
        int i = 0, j = 0, ans = INT_MAX;
        int sum = 0;

        for(j = 0;j<n;j++){
            sum += nums[j];

            while((j-i+1) > k){
                sum -= nums[i];
                i++; 
            }
            if((j-i+1) == k){
                ans = min(ans,sum);
                cout<<ans<<endl;
            }

        }
        return ans;
    }
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = f(nums,n - k);
        // cout<<sum<<endl;

        return accumulate(nums.begin(),nums.end(),0) - sum ;
    }
};