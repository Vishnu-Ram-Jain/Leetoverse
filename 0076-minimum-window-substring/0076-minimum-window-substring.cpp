class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())return "";

        vector<int> mp(128,0);
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int i = 0,j = 0, ans = 1e8, start = 0;
        int sz = 0;

        for(j = 0;j<s.length();j++){
            mp[s[j]]--;

            if(mp[s[j]] >= 0)sz++;

            while(sz == t.length()){
                if(ans > (j-i+1)){
                    ans = j-i+1;
                    start= i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0)sz--;

                i++;
            }


        }
        return ans == 1e8 ? "" : s.substr(start,ans);
    }
};