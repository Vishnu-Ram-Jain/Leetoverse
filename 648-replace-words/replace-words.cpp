class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        unordered_map<string,int> mp;
        for(auto &i : dictionary)mp[i]++;
        int n = s.size();
        string t = "";
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                ans += s[i];
                t = "";
                continue;
            }
            ans += s[i];
            t += s[i];
            if(mp.find(t) != mp.end()){
                while(i < n && s[i] != ' ')i++;
                if(i == n)break;
                t = "";
                ans += ' ';
            }
        }
        return ans;
    }
}; 