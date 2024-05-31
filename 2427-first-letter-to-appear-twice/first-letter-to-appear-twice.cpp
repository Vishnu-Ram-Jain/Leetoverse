class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mp;
        for(auto i : s){
            if(mp.find(i) != mp.end())return i;
            mp[i]++;
        }
        return 'z';
    }
};