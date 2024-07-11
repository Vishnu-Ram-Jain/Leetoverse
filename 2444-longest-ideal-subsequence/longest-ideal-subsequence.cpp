class Solution {
public:
    bool check(int a, int b, int k){
        return abs(b-a) <= k;
    }
    int dp[100001][40];
    int f(int i, int prev, string &s, int k){
        if(i >= s.size())return 0;

        if(dp[i][prev+1] != -1)return dp[i][prev+1];

        int pick = 0;
        if(prev == -1 or check(s[i]-'a',prev,k)){
            pick = 1 + f(i+1,s[i]-'a',s,k);
        }
        int np = f(i+1,prev,s,k);

        return dp[i][prev+1] = max(pick,np); 
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,s,k);
    }
};