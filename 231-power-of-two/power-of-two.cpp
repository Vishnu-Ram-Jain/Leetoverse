class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num = (long long)n;
        if(num == 0)return false;
        if((num & (num-1)) == 0)return true;
        return false;
    }
};