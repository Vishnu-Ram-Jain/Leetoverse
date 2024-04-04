class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int op = 0, cl = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(')op++;
            if(s[i] == ')')cl++;
            maxi = max(op-cl,maxi);
        }
        return maxi;
    }
};