class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int row = -1, col = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0){
                    if(mat[i-1][j] >= mat[i][j])continue;
                }
                if(i<n-1){
                    if(mat[i+1][j] >= mat[i][j])continue;
                }
                if(j<m-1){
                    if(mat[i][j+1] >= mat[i][j])continue;
                }
                if(j>0){
                    if(mat[i][j-1] >= mat[i][j])continue;
                }
                return {i,j};
            }
        } 
        return {-1,-1};  
    }
};