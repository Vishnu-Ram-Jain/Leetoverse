class Solution {
public:
    int dp[100001][31];
    int f(int i, int prev, string &s, int k){
        if(i >= s.size())return 0;
        if(dp[i][prev] != -1)return dp[i][prev];

        int pick = 0, notpick = 0;

        int curr = s[i] - 'a' + 1;
        if(prev == 0 or abs(curr - prev) <= k){
            pick = 1 + f(i+1,curr,s,k);
        }
        notpick = f(i+1,prev,s,k);

        return dp[i][prev] = max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,k);
    }
};