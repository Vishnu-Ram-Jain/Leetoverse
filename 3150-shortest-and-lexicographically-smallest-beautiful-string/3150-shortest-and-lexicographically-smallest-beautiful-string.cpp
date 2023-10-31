class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0,j = 0, one = 0, st = 0, e = 0;
        int ans = INT_MAX;
        string res ;
        // for(int i = 0;i<n;i++){
        //     res+='1';
        // }

        for(j = 0;j<n;j++){
            if(s[j] == '1')one++;

            while(one == k){
                string w = s.substr(i,(j-i+1));

                if(ans > (j-i+1)){
                    ans = j-i+1;
                    st = i;
                    res = w;
                    
                }
                else if(ans == (j-i+1)){
                    ans = j-i+1;
                    st = i;
                    res = min(res,w);
                    
                }
                if(s[i] == '1')one--;
                i++;
            }
        }

        return ans == INT_MAX ? "" : res;
    }
};