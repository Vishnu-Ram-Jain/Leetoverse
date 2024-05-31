class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int m = n;
        n = abs(n);
        while(n > 0){
            if(n % 2 == 0){
                n /= 2;
                x = x * x;
            }
            else{
                ans *= x;
                n -= 1;
            }
        }
        // cout<<ans<<endl;
        return m < 0 ? 1.0/ans : ans;
    }
};