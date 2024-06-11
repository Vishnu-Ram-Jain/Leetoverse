class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto &i : arr1)mp[i]++;
        vector<int> v;
        for(auto &i : arr2){
            int freq = mp[i];
            mp.erase(i);
            while(freq--){
                v.push_back(i);
            }
        }

        for(auto &i : mp){
            int freq = i.second;
            // mp.erase(i);
            while(freq--){
                v.push_back(i.first);
            }
        }
        return v;
    }
};