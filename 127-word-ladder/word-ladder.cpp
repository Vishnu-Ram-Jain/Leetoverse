class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> mp;
        for(auto &it : wordList){
            mp[it] = 1;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string s = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(s == endWord)return dist;
            for(int i=0;i<s.size();i++){
                char org = s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i] = ch;
                    if(mp.find(s) != mp.end()){
                        q.push({s,1+dist});
                        mp.erase(s);
                    }
                }
                s[i] = org;
            }
        }
        return 0;
    }
};