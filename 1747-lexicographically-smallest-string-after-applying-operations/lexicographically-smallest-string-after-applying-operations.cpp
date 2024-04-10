class Solution {
public:
    string f(string &str, int b){
        int n = str.size();
        return str.substr(n-b) + str.substr(0,n-b);
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        queue<string> q;
        unordered_map<string,bool> vis;

        q.push(s);
        vis[s] = 1;
        string ans = s;
        while(!q.empty()){
            string str = q.front();
            q.pop();
            ans = min(ans,str);
            string rot = f(str,b);
            if(vis.find(rot) == vis.end()){
                vis[rot] = 1;
                q.push(rot);
            }
            string x = str; 
            for(int i=0;i<n;i++){
                if(i%2!=0){
                    int num = x[i] - '0';
                    num += a;
                    num = num % 10;
                    x[i] = num + '0';
                }
            }
            if(vis.find(x) == vis.end()){
                vis[x] = 1;
                q.push(x);
            }            

        }
        return ans;
    }
};