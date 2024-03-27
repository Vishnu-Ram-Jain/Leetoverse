class Solution {
public:
    typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& id, vector<int>& freq) {
        unordered_map<ll,ll> mp;
        
        int n = id.size();
        vector<ll> ans;
        set<pair<ll,ll>> st;
        for(int i=0;i<n;i++){
            if(st.find({mp[id[i]],id[i]}) != st.end())st.erase({mp[id[i]],id[i]});
            mp[id[i]] += freq[i];
            st.insert({mp[id[i]],(ll)id[i]});
            auto it = *st.rbegin();
            ans.push_back(it.first);
        }
        return ans;
    }
};