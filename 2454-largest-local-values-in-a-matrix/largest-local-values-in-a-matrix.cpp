class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c){
        int maxi=0;
        for(int i=r;i<=r+2;i++){
            for(int j=c;j<=c+2;j++){
                maxi=max(maxi,grid[i][j]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size()-2;
        vector<vector<int>> v(n,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i][j]=solve(grid,i,j);
            }
        }
        return v;

    }
};