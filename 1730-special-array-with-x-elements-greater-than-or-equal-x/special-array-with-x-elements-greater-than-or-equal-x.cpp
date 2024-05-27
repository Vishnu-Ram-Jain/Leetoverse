class Solution {
public:
    int specialArray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        for(auto i : nums)mp[i]++;

        for(int i=0;i<=maxi;i++){
            int val = i;
            int cnt = 0;
            for(auto it : mp){
                if(it.first >= i)cnt += it.second;
            }
            if(cnt == i)return i;
        }
        return -1;
    }
};