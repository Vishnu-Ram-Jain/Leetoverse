class Solution {
public:
    bool check(vector<int> &nums, int days, int mid){
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(sum <= mid){
                sum += nums[i];
                if(sum > mid){
                    days--;
                    sum = nums[i];
                    if(days < 0)return false;
                }
            }
        }
        if(sum <= mid && days >= 1)return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int s = 1;
        // int e = ac/cumulate(nums.begin(),nums.end(),0);
        int e = 1e9;
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;

            if(check(nums,days,mid)){
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