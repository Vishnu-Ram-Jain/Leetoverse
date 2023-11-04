class Solution {
public:
    int compress(vector<char>& arr) {
        vector<char> ans;

        int n = arr.size();
        int cnt = 1;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i] == ans.back())cnt++;
            else{
                if(cnt > 1 && cnt < 10){
                    string s = to_string(cnt);
                    ans.push_back(s[0]);
                }
                else if(cnt>=10){
                    string s = to_string(cnt);
                    for(int j=0;j<s.length();j++)ans.push_back(s[j]);
                }
                ans.push_back(arr[i]);
                cnt = 1;
            }
        }
        if(cnt > 1){
            string s = to_string(cnt);
            for(int j=0;j<s.length();j++)ans.push_back(s[j]);      
        }
        arr = ans;
        return ans.size();
    }
};