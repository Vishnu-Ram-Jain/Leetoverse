class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> hash(n+1,0);
        vector<int> pre(n,0);
        for(auto &it : bookings){
            hash[it[0] - 1] += it[2];
            hash[it[1]] -= it[2];
        }
        pre[0] = hash[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + hash[i];
        }
        return pre;
    }
};