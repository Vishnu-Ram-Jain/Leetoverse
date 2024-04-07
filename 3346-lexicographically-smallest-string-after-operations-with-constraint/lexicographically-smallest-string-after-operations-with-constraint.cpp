class Solution {
public:
    // int dist(string &s, string &t){
    //     int dst=0;
    //     for(int i=0;i<s.size();i++){
    //         if(s[i] != t[i]){
    //             int fwd = abs(s[i] - t[i]) ;
    //             int bwd = abs(26 - (s[i] - t[i]));
    //             dst += min(fwd,bwd);
    //         }
    //     }
    //     return dst;
    // }
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t = s;
        for(int i=0;i<n;i++){
            for(char ch = 'a';ch <= 'z';ch++){
                int dist = min(s[i]-ch,26-(s[i] - ch));
                if(dist <= k){
                    t[i] = ch;
                    k -= dist;
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