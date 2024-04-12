class Solution {
public:
    bool f(string &s, int i, int j, vector<vector<int>> &dp){
        if(i >= j)return true;

        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = f(s,i+1,j-1,dp);
        }
        else return dp[i][j] = 0;
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(s,i,j,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};