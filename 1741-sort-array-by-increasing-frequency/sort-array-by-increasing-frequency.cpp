class Compare {
public:
    typedef pair<int,int> pp;
    bool operator()(pp below, pp above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }

        return false;
    }
};
class Solution {
public:
     typedef pair<int,int> pp;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto i : nums){
            mp[i]++;
        }

        priority_queue<pp,vector<pp>,Compare> pq;
        // freq,val;
        for(auto &i : mp){
            pq.push({i.second,i.first});
        }

        vector<int> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int sz = it.first;
            while(sz--){
                ans.push_back(it.second);
            }
        }
        return ans;
        
    }
};