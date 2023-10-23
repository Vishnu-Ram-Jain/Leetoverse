class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i = 0,j = 0,ans = 0, one = 0, zero = 0;
        int n = s.length();
        for(j = 0;j<n;j++){
            if(s[j] == 'T')one++;
            else zero++;

            while(min(one,zero) > k){
                if(s[i] == 'T')one--;
                else zero--;
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};