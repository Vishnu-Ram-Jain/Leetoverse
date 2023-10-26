class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for(auto it : logs){
            mp[it[0]]++;
            mp[it[1]]--;
        }

        int sum = 0;
        int mx = 0;
        int year = 5000;

        for(auto &it : mp){
            sum += it.second;
            mx = max(mx,sum);
        }
        sum = 0;
        for(auto &it : mp){
            sum += it.second;
            if(sum == mx)return it.first;
        }
        
        return year;
    }
};