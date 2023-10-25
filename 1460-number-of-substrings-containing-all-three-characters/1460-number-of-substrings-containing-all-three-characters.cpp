class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char,int> mp;
        int n = s.length();
        int end = n-1;
        for(j = 0;j<n;j++){
            mp[s[j]]++;

            while(mp.size() == 3){
                ans += (end-j+1);
                mp[s[i]]--;
                if(mp[s[i]] == 0)mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};