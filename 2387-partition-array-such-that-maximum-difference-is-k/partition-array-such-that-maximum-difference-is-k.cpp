class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1)return 1;
        int ans = 1;
        int mini = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] - mini > k){
                ans++;
                mini = nums[i];
            }
            else{

            }
        }
        return ans;
    }
};