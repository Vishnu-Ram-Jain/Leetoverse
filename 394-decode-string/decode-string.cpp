class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<int> number;
        stack<string> str;
        int num = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] >= '0' && s[i] <= '9')num = num * 10 + s[i] - '0';

            else if(s[i] == '['){
                str.push(ans);
                ans = "";
                number.push(num);
                num = 0;
            }

            else if(s[i] == ']'){
                string temp = ans;
                ans = str.top();
                str.pop();
                int times = number.top();
                number.pop();
                while(times--){
                    ans += temp;
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};