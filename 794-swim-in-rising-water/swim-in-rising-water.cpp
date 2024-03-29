class Solution {
public:
    bool check(vector<vector<int>>& grid, vector<vector<int>>& vis, int k, int row, int col, int n){
        if(row == n-1 && col == n-1)return true;
        if(grid[row][col] > k)return false;
        vis[row][col] = 1;
        int dr[] = { -1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow>=0 && ncol>=0 && ncol<n && nrow<n && grid[nrow][ncol] <= k && !vis[nrow][ncol]){
                if(check(grid,vis,k,nrow,ncol,n))return true;
            }
        }
        return false;

    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int e = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                e = max(e,grid[i][j]);
            }
        }

        int s = 0;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            vector<vector<int>> vis(n,vector<int>(n,0));
            if(check(grid,vis,mid,0,0,n)){
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