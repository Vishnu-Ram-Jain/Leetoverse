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
        // s[0]++;
        string orig = s;
        int n = s.size();
        map<string,bool> mp;
        for(int i=0;i<n;i++){
            // char ch = s[i];
            for(char c='a';c<='z';c++){
                char ch = s[i];
                s[i] = c;
                if(Palindrome(s) == 0){
                    mp[s] = 1;
                }
                s[i] = ch;
            }
            // s[i] = ch;
        }
        if(mp.size() == 0)return "";
        auto it = mp.begin();

        return it->first == s ? "" : it->first;
        // for(auto it : mp){
        //     cout<<it.first<<endl;
        // }
        // return "";
    }
};