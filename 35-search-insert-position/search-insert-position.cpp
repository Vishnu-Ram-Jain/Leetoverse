class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans == -1 ? n : ans;
    }
};