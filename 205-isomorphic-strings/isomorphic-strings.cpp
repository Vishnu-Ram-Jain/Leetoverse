class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool> mm;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i])return false;
            }
            else{
                if(mm.find(t[i]) != mm.end())return false;
                mp[s[i]] = t[i];
                mm[t[i]] = 1;
            }
        }
        return true;
    }
};