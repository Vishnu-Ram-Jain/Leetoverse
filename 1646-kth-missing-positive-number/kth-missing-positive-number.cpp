class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(nums[mid] - (mid+1) < k)s = mid+1;

            else e = mid-1;
        }
        return 1 + e + k;
    }
};