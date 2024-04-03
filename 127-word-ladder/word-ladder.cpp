class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> mp;
        
        for(auto i : wordList) mp[i] = 1;

        queue<pair<int,string>> q;
        q.push({1,beginWord});

        while(!q.empty()){
            string temp = q.front().second;
            int steps = q.front().first;
            q.pop();
            if(temp == endWord)return steps;

            for(int i=0;i<temp.size();i++){
                char orig = temp[i];
                for(char ch='a';ch<='z';ch++){
                    temp[i] = ch;
                    if(mp.find(temp) != mp.end()){
                        q.push({1+steps,temp});
                        mp.erase(temp);
                    }
                }
                temp[i] = orig;
            }
        }
        return 0;
    }
};