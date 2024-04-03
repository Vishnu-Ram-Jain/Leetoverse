class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int countPairs(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_map<ll,int> mm;
        vector<ll> power(22,0);

        for(int i=0;i<22;i++){
            power[i] = (ll)pow(2,i);
        }
        int cnt = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int val = arr[i];

            for(int j=0;j<22;j++){
                int rem = power[j] - val;
                if(rem<0)continue;
                if(mp.find(rem) != mp.end())cnt = (cnt + mm[rem]) % mod;
            }
            mp[arr[i]] = i;
            mm[arr[i]]++;
        }
        return cnt % mod;
    }
};