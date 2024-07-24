class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int sz = min(n,m);

        int i=0,j=0;
        bool fl = true;
        string res = "";
        while(i < n && j < m){
            if(fl)res += word1[i++];
            else res += word2[j++];
            fl = !fl;
        }

        while(i < n){
            res += word1[i++];
        }

        while(j < m){
            res += word2[j++];
        }
        return res;
    }
};