class Solution {
public:
    bool prime[5000001];
    void blackbox(int n){
        prime[0] = prime[1] = 0;

        for(int i=2;i<=n;i++)prime[i] = 1;

        for(int i=2;i*i<=n;i++){
            if(prime[i] == 1){
                for(int j=i*i;j<=n;j+=i){
                    prime[j] = 0;
                }
            }
        }
    }
    int countPrimes(int n) {
        blackbox(n);
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(prime[i])cnt++;
        }
        return cnt;
    }
};