class Solution {
public:
    void dfs(int n, int m, vector<vector<int>> &img, int sr, int sc, 
        int inicolor, int color, vector<vector<int>> &vis){
        vis[sr][sc] = 1;
        img[sr][sc] = color;

        int delrow[]={0,-1,0,1};
        int delcol[]={1,0,-1,0};

        for(int i=0;i<4;i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && !vis[nrow][ncol] && img[nrow][ncol] == inicolor){
                dfs(n,m,img,nrow,ncol,inicolor,color,vis);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int n = img.size();
        int m = img[0].size();
        int inicolor = img[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(n,m,img,sr,sc,inicolor,color,vis);
        return img;

    }
};