class Solution {
public:
    bool f(int i, int j, string &x, string &y, vector<vector<int>> &dp,int n, int m){


        if(i >= n && j>= m)return true;
        if(i < n && j >= m)return false;
        if(i >= n && j < m){
            for(int k=j;k<m;k++){
                if(y[k] != '*')return false;
            }
            return true;
        }

        if(dp[i][j] != -1)return dp[i][j];
        bool a = 0;
        bool b = 0;
        if(x[i] == y[j] || y[j] == '?'){
            a = f(i+1,j+1,x,y,dp,n,m);
        }

        else if(y[j] == '*'){
            b = f(i+1,j,x,y,dp,n,m) || f(i,j+1,x,y,dp,n,m);
        }
        // return dp[i][j] = false;
        return dp[i][j] = a || b;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,s,p,dp,n,m);
    }
};