class Solution {
public:
    void reverse(vector<int> &arr, int i, int j){
        while(i <= j){
            swap(arr[i++],arr[j--]);
        }
    }
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();

        k = k % n;

        int ind = n - k;
        reverse(arr,ind,n-1);
        reverse(arr,0,ind-1);

        int i = 0, j = n-1;
        while(i <= j)swap(arr[i++],arr[j--]);
        
    }
};