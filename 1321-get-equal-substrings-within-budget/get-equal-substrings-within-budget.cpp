class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0,j = 0;
        int ans = 0;
        int cost = 0;
        int n = s.length();
        for(j = 0;j<n;j++){
            cost += abs(s[j] - t[j]);

            while(cost > maxCost){
                cost -= abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};