class Solution {
public:
    bool check(string &curr, string &prev){
        int n = curr.size();
        int m = prev.size();
        if(n - m != 1)return 0;

        int i = 0, j = 0;
        while(i < n && j < m){
            if(curr[i] == prev[j]){
                i++,j++;
            }
            else{
                i++;
            }
        }

        return j >= m;
    }
    int dp[1001][1001];
    int f(int i, int prev_i, vector<string>& nums){
        if(i >= nums.size())return 0;

        if(dp[i][prev_i+1] != -1)return dp[i][prev_i+1];
        
        int pick = 0;
        if(prev_i == -1 or check(nums[i],nums[prev_i])){
            pick = 1 + f(i+1,i,nums);
        }
        int np = f(i+1,prev_i,nums);

        return dp[i][prev_i+1] = max(pick,np);
    }
    static bool cmp(string &a, string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        memset(dp,-1,sizeof(dp));
        return f(0,-1,words);
    }
};