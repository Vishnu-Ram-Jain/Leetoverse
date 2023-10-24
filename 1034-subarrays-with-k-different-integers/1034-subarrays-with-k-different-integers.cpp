class Solution {
public:
    int f(vector<int> &nums, int k){
        map<int,int> mp;
        int i = 0,j =0,ans = 0;
        int n = nums.size();

        for(j = 0;j<n;j++){
            mp[nums[j]]++;

            while(i <= j && mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};