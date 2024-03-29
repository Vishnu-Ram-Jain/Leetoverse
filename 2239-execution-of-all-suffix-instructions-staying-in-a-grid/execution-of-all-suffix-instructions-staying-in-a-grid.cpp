class Solution {
public:
vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
    pair<int,int> f(char &ch){
        int nrow = -1, ncol = -1;
        if(ch == 'L'){
            nrow = dir[0].first;
            ncol = dir[0].second;
        }
        else if(ch == 'U'){
            nrow = dir[1].first;
            ncol = dir[1].second;
        }
        else if(ch == 'R'){
            nrow = dir[2].first;
            ncol = dir[2].second;
        }
        else if(ch == 'D'){
            nrow = dir[3].first;
            ncol = dir[3].second;
        }

        return {nrow,ncol};

    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        // int n = s.size();
        int sz = s.size();
        vector<int> v(sz,0);
        for(int i=0;i<sz;i++){
            int cnt = 0;
            int row = startPos[0];
            int col = startPos[1];
            for(int j=i;j<sz;j++){
                int nrow = row + f(s[j]).first;
                int ncol = col + f(s[j]).second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                    cnt++;
                    row = nrow;
                    col = ncol;
                }
                else{
                   break;
                }
            }
            v[i] = cnt;
        }
        return v;
    }
};