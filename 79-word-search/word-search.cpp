class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, string word,
    int ind, int delrow[], int delcol[], int n, int m){
        if(ind >= word.size())return true;

        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && 
            mat[nrow][ncol] == word[ind]){
                if(dfs(nrow,ncol,vis,mat,word,ind+1,delrow,delcol,n,m))return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0] == board[i][j]){
                    if(dfs(i,j,vis,board,word,1,delrow,delcol,n,m))return true;
                }
            }
        }
        return false;
    }
};