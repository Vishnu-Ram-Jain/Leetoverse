class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> mat(n*n+1,-1);
        vector<int> vis(n*n+1,0);
        bool f = 1;
        int cnt = 1;
        for(int i=n-1;i>=0;i--){
            if(f){
                for(int j=0;j<n;j++){
                    mat[cnt++] = board[i][j];
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    mat[cnt++] = board[i][j];
                }
            }
            f = !f;
        }

        queue<pair<int,int>> q;
        // steps,node
        q.push({0,1});
        vis[1] = 1;
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            if(node == n*n)return steps;

            for(int i=1;i<=6&&(node+i<=n*n);i++){
                if(vis[node+i])continue;
                if(mat[node+i] == -1) q.push({1+steps,node+i});
                else q.push({1+steps,mat[node+i]});
                vis[node+i] = 1;
            }
        }

        return -1;
    }
};