class Solution {
public:
    int findJudge(int n, vector<vector<int>>& arr) {
        if(n==1)return 1;
        unordered_map<int,int> mp;
        unordered_map<int,int> mm;
        for(int i=0;i<arr.size();i++){
            mp[arr[i][1]]++;
            mm[arr[i][0]]++;
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second==n-1)ans = it.first;
        }
        if(ans==0)return -1;
        if(mm.find(ans) == mp.end())return ans;
        return -1;
    }
};