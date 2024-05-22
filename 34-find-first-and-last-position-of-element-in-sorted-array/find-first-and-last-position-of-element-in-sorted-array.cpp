class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int high = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        cout<<low<<high<<endl;
        if(low < n && high <= n && nums[low] == target && nums[high-1] == target)return {low,high-1};
        cout<<low<<high<<endl;

        return {-1,-1};
    }
};