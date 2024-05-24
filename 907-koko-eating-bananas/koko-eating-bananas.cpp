class Solution {
public:
    bool check(vector<int> &nums, int h, int mid){
        int n = nums.size();
        long long val = 0;
        for(int i=0;i<n;i++){
            val += ceil(1.0 * nums[i]/mid);
        }
        return val <= h;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(check(nums,h,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};