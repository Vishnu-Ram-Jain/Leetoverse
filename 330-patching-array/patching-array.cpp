class Solution {
public:
    typedef long long ll;
    int minPatches(vector<int>& nums, int n) {
        ll ob = 0;
        int addedcnt = 0;

        for(auto coin : nums){

            while(coin > ob+1){
                addedcnt++;
                ll newcoin = ob+1;
                ob += newcoin;
                if(ob >= n)return addedcnt;
            }
            ob += coin;
            if(ob >= n)return addedcnt;
        }

        while(ob < n){
            addedcnt++;
            ll newcoin = ob+1;
            ob += newcoin;
        }

        return addedcnt;
    }
};