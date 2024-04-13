class Solution {
public:
    vector<int> nsr(vector<int> &nums){
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<int> left(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i] <= st.top().first){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top().second;
            }
            else{
                left[i] = n;
            }
            st.push({nums[i],i});
        }
        return left;
    }
    vector<int> nsl(vector<int> &nums){
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<int> right(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i] <= st.top().first){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top().second;
            }
            else{
                right[i] = -1;
            }
            st.push({nums[i],i});
        }
        return right;
    }
    int mah(vector<int>& h) {
        int n = h.size();
        vector<int> next(n);
        vector<int> prev(n);
        next = nsr(h);
        prev = nsl(h);
        vector<int> width(n,0);
        int maxi = -1;
        for(int i=0;i<n;i++){
            width[i] = next[i] - prev[i] - 1;
            int prod = width[i] * h[i];
            maxi = max(maxi,prod);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = -1;
        vector<int> v(m,0);
        for(int i=0;i<m;i++){
            v[i] = mat[0][i] - '0';
        }
        maxi = max(maxi,mah(v));
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == '1'){
                    v[j] = 1 + v[j];
                }
                else{
                    v[j] = 0;
                }
            }
            maxi = max(maxi,mah(v));
        }
        return maxi;
    }
};