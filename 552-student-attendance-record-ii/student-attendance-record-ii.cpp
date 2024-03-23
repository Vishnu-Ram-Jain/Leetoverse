class Solution {
public:
    int mod = 1e9 + 7;
    int dp[(int)(1e5+1)][2][3];
    int f(int n, bool markabs, int late_cnt){
        if(n == 0)return 1;
        if(n < 0)return 0;

        if(dp[n][markabs][late_cnt] != -1)return dp[n][markabs][late_cnt];
        // present case;
        if(markabs == false){
            int present = f(n-1,false,0);
            int late = 0;
            if(late_cnt < 2){
                late = f(n-1,false,late_cnt+1);
            }
            int absent = f(n-1,true,0);
            return dp[n][markabs][late_cnt] = (((present + late) % mod) + absent) % mod; 
        }
        // absent case;
        else{
            int present = f(n-1,true,0);
            int late = 0;
            if(late_cnt < 2){
                late = f(n-1,true,late_cnt+1);
            }
            return dp[n][markabs][late_cnt] = (present + late) % mod;
        }
    }
    int checkRecord(int n) {
        // return 0;
        memset(dp,-1,sizeof(dp));
        return f(n,false,0);
    }
};