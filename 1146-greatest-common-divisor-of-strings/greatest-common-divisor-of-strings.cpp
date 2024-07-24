class Solution {
public:
    string gcdOfStrings(string x, string y) {
        if(x + y != y + x)return "";
        int n = x.size();
        int m = y.size();

        int len = __gcd(n,m);
        return x.substr(0,len);
    }
};