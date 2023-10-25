class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        int n = s.length();
        map<char,int> mp;

        for(j = 0;j<n;j++){
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};