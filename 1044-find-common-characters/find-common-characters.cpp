class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size(), j;
        vector<array<int, 26>> freq(n - 1);
        for (int i = 1; i < n; i++)
            for (char c : words[i])
                freq[i-1][c-'a']++;
        vector<string> res;
        for (char c : words[0]){
            for (j = 1; j < n; j++){
                if (freq[j-1][c-'a'])
                    freq[j-1][c-'a']--;
                else
                    break;
            }
            if (j == n){
                string s(1, c);
                res.push_back(s);
            }
        }
        return res;
    }
};