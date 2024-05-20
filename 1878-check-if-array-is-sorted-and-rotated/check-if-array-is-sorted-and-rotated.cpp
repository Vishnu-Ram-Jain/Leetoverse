class Solution {
public:
    bool f(vector<int>& arr, int n) {
        // code here
        for(int i=0;i<n-1;i++){
            if(arr[i] > arr[i+1])return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int x=0;x<=n-1;x++){
            vector<int> arr(n,0);
            for(int i=0;i<n;i++){
                arr[i] = nums[(i+x)%n];
            }
            if(f(arr,n))return true;
            // nums = arr;
        }
        return false;
    }
};