class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // unordered_map<char,char> mp;
        // unordered_map<char,bool> mm;
        vector<int> mp(256,0);
        vector<bool> mm(256,0);
        for(int i=0;i<s.size();i++){
            if(mp[s[i]] != 0){
                if(mp[s[i]] != t[i])return false;
            }
            // if(mp.find(s[i]) != mp.end()){
            //     if(mp[s[i]] != t[i])return false;
            // }
            // else{
            //     if(mm.find(t[i]) != mm.end())return false;
            //     mp[s[i]] = t[i];
            //     mm[t[i]] = 1;
            // }
            else{
                if(mm[t[i]] != 0)return false;
                mp[s[i]] = t[i];
                mm[t[i]] = 1;
            }
        }
        return true;
    }
};