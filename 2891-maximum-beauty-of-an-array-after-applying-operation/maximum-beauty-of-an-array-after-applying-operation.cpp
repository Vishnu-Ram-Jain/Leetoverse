class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i=0,j=0,ans=0,n=nums.size();
        k *= 2;
        for(j=0;j<n;j++){

            while(nums[j] - nums[i] > k)i++;

            ans = max(ans,j-i+1);
        }
        return ans;
    }
};