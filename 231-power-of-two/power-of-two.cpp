class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        int cnt = 0;
        while(n != 0){
            int bit = n & 1;
            if(bit==1)cnt++;
            n = n>>1;
            if(cnt>1)return false;
        }
        return true;
     
    }
};