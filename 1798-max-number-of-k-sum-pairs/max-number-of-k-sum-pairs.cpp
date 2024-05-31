class Solution {
public:

    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0;

        for(int i=0;i<n;i++){
            int rem = k - nums[i];
            if(mp.find(rem) != mp.end()){
                cnt++;
                mp[rem]--;
                if(mp[rem] == 0)mp.erase(rem);
            }
           else mp[nums[i]]++;
        }
        return cnt;
    }
};