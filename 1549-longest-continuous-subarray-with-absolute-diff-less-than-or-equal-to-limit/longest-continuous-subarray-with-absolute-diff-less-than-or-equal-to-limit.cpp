class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mp;
        int i=0,j=0,n=nums.size(),ans=0;

        for(j=0;j<n;j++){
            mp[nums[j]]++;

            while(abs(mp.begin()->first-mp.rbegin()->first) > limit){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
                i++;
            }

            ans = max(ans,j-i+1);
        }

        return ans;
    }
};