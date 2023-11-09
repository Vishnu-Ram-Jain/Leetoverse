class Solution {
public:
    typedef long long ll;
    int countHomogenous(string s) {
        int n = s.length();
        int mod = 1e9+7;
        int ans = 0;
        ll cnt = 0;
        char pre = '#';
        for(int i=0;i<n;i++){
            if(s[i] == pre){
                cnt++;
            }
            else{
                 ans = (ans + (cnt%mod*(cnt+1)%mod)/2)%mod;
                cnt = 1;
                pre = s[i];
            }
        }
         ans = (ans + (cnt%mod*(cnt+1)%mod)/2)%mod;
        return ans;
    }
};