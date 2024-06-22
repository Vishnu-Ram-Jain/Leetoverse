class Solution {
public:
    int f(vector<int> &nums, int k){
        int i = 0,j = 0, ans = 0, cnt = 0;
        int n = nums.size();
        for(j = 0;j<n;j++){
            if(nums[j] % 2 != 0){
                cnt++;
            }

            while(cnt > k){
                if(nums[i] % 2 != 0){
                    cnt--;
                }
                i++;
            }

            ans += (j-i+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};