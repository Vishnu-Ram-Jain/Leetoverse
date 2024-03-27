class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long m=0;
        int n = s.size();
        for(int k=0;k<n;k++){
            if(s[k] == c){
                m++;
            }
        }
        return m*(m+1)/2;
    }
};