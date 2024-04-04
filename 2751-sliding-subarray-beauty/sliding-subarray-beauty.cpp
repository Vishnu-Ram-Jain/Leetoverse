class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v;
        int i=0,j=0,n=nums.size();
        map<int,int> mp;
        bool f = 0;
        for(j=0;j<n;j++){
            mp[nums[j]]++;

            while(j-i+1 > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
                i++;
            }
            if(j-i+1 == k){
                f = 1;
                int cnt = 0;
                for(auto it : mp){
                    cnt += it.second;
                    if(cnt >= x){
                        if(it.first > 0)v.push_back(0);
                        else v.push_back(it.first);
                        break;
                    }
                }
            }
        }

        if(f == 0){
            int cnt = 0;
            for(auto it : mp){
                cnt += it.second;
                if(cnt >= x){
                    if(it.first > 0)v.push_back(0);
                    else v.push_back(it.first);
                    break;
                }
            }
        }
        return v;
    }
};