class Solution {
public:
    bool f(string &s, int open, int i, vector<vector<int>> &dp){
        if(i >= s.size())return open==0;
        if(dp[i][open] != -1)return dp[i][open];

        if(s[i] == '('){
            return dp[i][open] = f(s,open+1,i+1,dp);
        }
        else if(s[i] == ')'){
            if(open==0) return dp[i][open] = false;
            else return dp[i][open] = f(s,open-1,i+1,dp);
        }
        else if(s[i] == '*'){
            bool op1=0,op2=0,op3=0;
            op1 = f(s,open+1,i+1,dp);
            if(open)op2 = f(s,open-1,i+1,dp);
            op3 = f(s,open,i+1,dp);

            return dp[i][open] = op1 || op2 || op3;
        }
        return true;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(s,0,0,dp);
    }
};