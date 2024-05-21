class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int price = arr[0];
        int maxprofit = 0;
        for(int i=0;i<n;i++){
            int profit = arr[i] - price;
            maxprofit = max(maxprofit,profit);
            if(profit < 0)price = arr[i];
        }
        return maxprofit;
    }
};