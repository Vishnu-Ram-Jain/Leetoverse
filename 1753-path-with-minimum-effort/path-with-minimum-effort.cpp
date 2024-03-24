class Solution {
public:
    bool check(vector<vector<int>>& h, int mid, int row, int col, int n, int m,
        vector<vector<bool>> &vis){

        if(row == n-1 && col == m-1)return true;
        vis[row][col] = 1;

        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && 
                abs(h[nrow][ncol] - h[row][col]) <= mid && !vis[nrow][ncol]){
                    if(check(h,mid,nrow,ncol,n,m,vis))return true;
                }
        }
        // vis[row][col] = 0;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        int s = 0;
        int e = 1e9;
        int ans = 0;
        while(s <= e){
            vector<vector<bool>> vis(n,vector<bool>(m,0));
            int mid = s+(e-s)/2;

            if(check(h,mid,0,0,n,m,vis)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};