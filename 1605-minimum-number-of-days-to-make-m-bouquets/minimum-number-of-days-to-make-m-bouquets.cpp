class Solution {
public:
    bool check(vector<int> &nums, int m, int k, int mid){
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] <= mid){
                cnt++;
                if(cnt == k){
                    cnt=0;
                    m--;
                }
            }
            else{
                if(cnt == k)m--;
                cnt = 0;
            }
        }
        if(cnt == k)m--;
        return m<=0;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;

            if(check(nums,m,k,mid)){
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