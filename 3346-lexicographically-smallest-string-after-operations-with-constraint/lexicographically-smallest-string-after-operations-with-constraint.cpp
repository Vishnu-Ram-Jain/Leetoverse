class Solution {
public:
    int dist(string &s, string &t){
        int dst=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i]){
                int fwd = (s[i] - t[i]) ;
                int bwd = 26 - (s[i] - t[i]);
                dst += min(fwd,bwd);
            }
        }
        return dst;
    }
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t = s;
        for(int i=0;i<n;i++){
            for(char ch = 'a';ch <= 'z';ch++){
                t[i] = ch;
                if(dist(s,t) <= k){
                    t = min(t,s);
                    break;
                }
            }
        }
        // int ch = 26 - ('x' - 'a') + 1;
        // int ch = 'c' - 'a' + 1;
        
        // cout<<ch<<endl;
        return t;




    }
};