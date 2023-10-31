class Solution {
public:
    vector<int> findArray(vector<int>& pre) {
        int n = pre.size();
        vector<int> ans(n,0);
        ans[0] = pre[0];
        int cxor = pre[0];

        for(int i = 1;i<n;i++){
            ans[i] = cxor ^ pre[i];
            cxor = cxor ^ ans[i];
        }
        return ans;
    }
};