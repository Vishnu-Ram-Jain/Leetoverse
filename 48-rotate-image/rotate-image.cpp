class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }

        }
        // vector<vector<int>> ans(n,vector<int>(n,0));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         ans[j][n-i-1] = matrix[i][j];
        //     }
        // }
        // matrix = ans;
 
    }
};