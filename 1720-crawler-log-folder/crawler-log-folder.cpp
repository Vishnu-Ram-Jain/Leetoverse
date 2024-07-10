class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto &it : logs){
            string s = it;
            if(s == "../"){
                if(cnt > 0)cnt--;
            }
            else if(s == "./"){
                continue;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};