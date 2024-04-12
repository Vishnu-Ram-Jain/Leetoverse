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
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int maxlen = -1;
        int start_ind = -1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(s,i,j,dp)){
                    if(maxlen < j-i+1){
                        maxlen = j-i+1;
                        start_ind = i;
                    }
                }
            }
        }
        return s.substr(start_ind,maxlen);
    }
};