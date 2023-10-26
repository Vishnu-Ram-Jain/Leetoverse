class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto it : trips){
            mp[it[1]] += it[0];
            mp[it[2]] -= it[0];
        }
        int sum = 0;

        for(auto &it : mp){
            sum += it.second;
            if(sum > capacity)return false;
        }
        return true;
    }
};