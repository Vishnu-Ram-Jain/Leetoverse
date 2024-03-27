class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> pp;
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        ll sum = (ll)accumulate(nums.begin(),nums.end(),0LL);
        unordered_map<ll,bool> mp;
        // priority_queue<pp,vector<pp>,greater<pp>> pq;
        set<pp> st;
        for(int i=0;i<nums.size();i++){
            // pq.push({nums[i],i});
            st.insert({nums[i],i});
        }
        vector<ll> ans;
        for(auto it : queries){
            ll ind = it[0];
            ll sz = it[1];
            if(mp.find(ind) == mp.end()){
                sum -= nums[ind];
                mp[ind] = 1;
                st.erase({nums[ind],ind});
            }
            for(;sz!=0 && st.size() > 0;sz--){
                // cout<<it.first<<" "<<it.second<<endl;
                auto it = *st.begin();
                sum -= it.first;
                mp[it.second] = 1;
                st.erase(it);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};