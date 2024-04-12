class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);

        pre[0] = arr[0];
        suff[n-1] = arr[n-1];

        for(int i=1;i<n;i++)pre[i] = max(pre[i-1],arr[i]);
        for(int i=n-2;i>=0;i--)suff[i] = max(suff[i+1],arr[i]);

        int sum = 0;

        for(int i=0;i<n;i++){
            int width = min(pre[i],suff[i]) - arr[i];
            sum += width;
        }
        return sum;
    }
};