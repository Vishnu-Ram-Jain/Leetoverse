class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) { 
        ll s = 0;
        ll e = x;
        int ans = -1;

        while(s <= e){
            ll mid = s+(e-s)/2;

            if(mid * mid == (ll)x)return mid;

            else if(mid * mid > x)e = mid-1;

            else{
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }
};