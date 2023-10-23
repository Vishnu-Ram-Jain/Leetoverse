class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)return 0;
        if(n == 1)return 1;
        double ans = log(n) / log(4);
        return ans == (int) ans;
    }
};