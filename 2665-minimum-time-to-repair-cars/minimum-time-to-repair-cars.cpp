class Solution {
public:
    typedef long long ll;
    bool check(vector<int> &nums, int c, ll mid){
        int n = nums.size();
        ll tm = 0;
        for(int i=0;i<n;i++){
            ll num = pow(mid/nums[i],0.5);
            tm += num;
        }
        return tm >= c;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll s = 1;
        ll e = 1e14;
        ll ans = -1;

        while(s<=e){
            ll mid = s+(e-s)/2;

            if(check(ranks,cars,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};