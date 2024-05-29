class Solution {
public:
    int numSteps(string s) {
        // if(s == "1")return 0;
        int n = s.size();
        int i = n-1;
        int cnt = 0;
        while(s != "1"){
            if(s[i] == '0')s.pop_back();
            else{
                int j = i;
                while(j >= 0 && s[j] != '0'){
                    s[j] = '0';
                    j--;
                }
                if(j >= 0)s[j] = '1';
                else{
                    string t = "";
                    t += '1';
                    t += s;
                    s = t;
                }
            }
            i = s.length()-1;
            cnt++;
            // if(s == "1")return cnt;
        }
        return cnt;
    }
};