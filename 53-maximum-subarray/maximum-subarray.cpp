class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = -1e9;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];

                maxsum = max(maxsum,sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxsum;
    }
};