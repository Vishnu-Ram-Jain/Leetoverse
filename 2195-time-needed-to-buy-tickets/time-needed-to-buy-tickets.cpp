class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        while(arr[k] != 0){

            for(int i=0;i<n;i++){
                if(arr[i] > 0){
                    cnt++;
                    arr[i]--;
                    if(arr[k] == 0)return cnt;
                }
            }
        }
        return cnt;

    }
};