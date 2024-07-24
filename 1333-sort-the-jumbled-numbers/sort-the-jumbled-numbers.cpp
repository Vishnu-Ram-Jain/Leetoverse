class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    static bool cmp(pp s, pp e){
        if(s.first == e.first){
            return e.second.second > s.second.second;
        }
        return s.first < e.first;
    }
    vector<int> sortJumbled(vector<int>& mapp, vector<int>& nums) {
        vector<pair<int,pair<int,int>>> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            string res = "";
            for(auto ch : s){
                res += to_string(mapp[ch - '0']);
            }
            v.push_back({stoi(res),{nums[i],i}});
        }

        vector<int> ans;
        sort(v.begin(),v.end(),cmp);

        for(auto it : v){
            ans.push_back(it.second.first);
        }

        return ans;
    }
};