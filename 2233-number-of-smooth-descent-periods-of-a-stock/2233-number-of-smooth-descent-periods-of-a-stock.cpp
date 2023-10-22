class Solution {
public:
    typedef long long ll;
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        ll i = 0,j = 1,ans = 0;
        for(j = 1;j<n;j++){
            while( j < n && nums[j] - nums[j-1] == -1 ){
                ans += (j-i);
                j++;
            }
            i = j;
        }
        return ans + n;

         
    }
};