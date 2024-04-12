class Solution {
public:
    int findMinimumOperations(string x, string y, string z) {
        int n = min(x.size(),min(y.size(),z.size()));
        int ind = 0;
        for(int i=0;i<n;i++){
            if(x[i] == y[i] && y[i] == z[i]){
                ind++;
            }
            else break;
        }

        if(ind == 0)return -1;
        return x.size() + y.size() + z.size() - 3 *ind;
    }
};