class Solution {
public:
    bool check(vector<int> &arr, int mid, int k){
        int cnt = 1;
        int prev = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i] - prev >= mid){
                cnt++;
                prev = arr[i];
            }
        }
        return cnt >= k;
    }
    int maxDistance(vector<int>& arr, int m) {
        int s = 1;
        int e = 1e9;
        int ans = -1;
        sort(arr.begin(),arr.end());
        while(s <= e){
            int mid = s+(e-s)/2;
            if(check(arr,mid,m)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};