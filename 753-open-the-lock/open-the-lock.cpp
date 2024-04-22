class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int,string>> q;
        unordered_map<string,bool> mp;
        for(auto it : deadends)mp[it] = 1;
        if(mp.find("0000") != mp.end())return -1;
        if(target == "0000")return 0;

        q.push({0,"0000"});

        while(!q.empty()){
            int steps = q.front().first;
            string s = q.front().second;
            q.pop();
            if(target == s)return steps;

            for(int i=0;i<4;i++){
                char orig = s[i];
                for(int j=0;j<=9;j++){
                    if(s[i] == '9')s[i] = '0';
                    else s[i] = s[i] + 1;
                    if(mp.find(s) == mp.end()){
                        q.push({1+steps,s});
                        mp[s] = 1;
                    }
                    s[i] = orig;
                    if(s[i] == '0')s[i] = '9';
                    else s[i] = s[i] - 1;
                    if(mp.find(s) == mp.end()){
                        q.push({1+steps,s});
                        mp[s] = 1;
                    }
                    s[i] = orig;
                }
            }
        }
        return -1;
    }
};