class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26,0);
        int i = 0,j = 0, ans = 0;
        int n = s.length();
        for(j = 0;j<n;j++){
            mp[s[j] - 'A']++;

            while((j-i+1) - *max_element(mp.begin(),mp.end()) > k){
                mp[s[i] - 'A']--;
                i++;
            }

            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};