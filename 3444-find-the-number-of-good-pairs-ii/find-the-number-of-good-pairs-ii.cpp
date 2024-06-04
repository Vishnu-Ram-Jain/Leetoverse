class Solution {
public:
    typedef long long ll;
    ll f(ll n, unordered_map<ll,ll> &mp){
        ll num = n;
        ll cnt = 0;
        for(int i=1;i*i<=n;i++){
            if(n % i == 0){
                if(mp.find(i) != mp.end())cnt += mp[i];
                if(n/i != i){
                    if(mp.find(n/i) != mp.end())cnt += mp[n/i];
                }
            }
        }
        return cnt;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<ll,ll> mp;
        for(auto &i : nums2){
            ll ele = i * k;
            mp[ele]++;
        }
        ll cnt = 0;
        for(int i=0;i<nums1.size();i++){
            cnt += f(nums1[i],mp);
        }
        return cnt;


    }
};