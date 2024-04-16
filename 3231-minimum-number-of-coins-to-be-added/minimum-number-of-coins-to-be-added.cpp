class Solution {
public:
    
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int ob = 0;
        int addedcnt = 0;
        for(auto coin : coins){

            while(coin > ob+1){
                addedcnt++;
                int newcoin = ob+1;
                ob += newcoin;
                if(ob >= target)return addedcnt;
            }
            ob += coin;
            if(ob >= target)return addedcnt;
        }

        while(ob < target){
            addedcnt++;
            int newcoin = ob+1;
            ob += newcoin;
        }

        return addedcnt;
    }
};