class Solution {
public:
    bool isVowel(char &ch){
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i = 0, j = 0, cnt = 0, len = 0;
        int n = s.length();

        for(j = 0;j<n;j++){
            if(isVowel(s[j]))cnt++;

            while((j-i+1) > k){
                if(isVowel(s[i]))cnt--;
                i++;
            }

            if((j-i+1) == k)len = max(len,cnt);
        }
        return len;
    }
};