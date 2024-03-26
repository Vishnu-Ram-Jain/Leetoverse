class Solution {
public:
    bool Palindrome(string &s){
        int i=0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i] != s[j])return false;
            i++,j--;
        }
        return true;
    }
    string breakPalindrome(string s) {
        string orig = s;
        int n = s.size();
        unordered_map<string,bool> mp;
        for(int i=0;i<n;i++){
            for(char c='a';c<='z';c++){
                char ch = s[i];
                s[i] = c;
                if(Palindrome(s) == 0){
                    mp[s] = 1;
                }
                s[i] = ch;
            }
        }
        if(mp.size() == 0)return "";
        auto it = mp.begin();

        string temp = it->first;

        for(auto it : mp){
            if(temp > it.first)temp = it.first;
        }
        return temp;
    }
};