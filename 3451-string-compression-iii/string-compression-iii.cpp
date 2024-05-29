class Solution {
public:
    string compressedString(string s) {
        int n = s.size();
        char pre = s[0];
        string ans = "";
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(pre == s[i]){
                cnt++;
                if(cnt == 10){
                    ans += '9';
                    ans += pre;
                    cnt = 1;
                }
            }
            else{
                ans += to_string(cnt);
                ans += pre;
                cnt = 1;
                pre = s[i];
            }
        }
        ans += to_string(cnt);
        ans += pre;
        return ans;
    }
};