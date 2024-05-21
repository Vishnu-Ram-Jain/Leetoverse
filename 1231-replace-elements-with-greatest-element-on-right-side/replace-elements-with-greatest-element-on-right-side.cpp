class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> v;
        int n = arr.size();
        vector<int> ans(n,0);
        ans[n-1] = -1;
        v.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            ans[i] = v.back();
            if(arr[i] >= v.back())v.push_back(arr[i]);
        }
        return ans;
    }
};