class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)return 1;
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += i;
        }
        int left = 0;
        int right = 0;
        for(int i=1;i<=n;i++){
            left += i;
            right = i + sum - left;
            if(left == right)return i;
            else right = 0;
        }
        return -1;
    }
};