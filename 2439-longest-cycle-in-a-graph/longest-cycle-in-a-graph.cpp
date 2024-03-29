class Solution {
public:
    void dfs(int node,vector<bool> &visited,vector<int> adj[], stack<int> &st)
    {
        visited[node] = true;
        for(auto neigh:adj[node])
        {
            if(visited[neigh] == false)
            {
                dfs(neigh,visited,adj,st);
            }
        }
        st.push(node);
    }
    void revDFS(int node,vector<bool> &visited,vector<int> transpose[], int &count)
    {
        visited[node] = true;
        count++;
        for(auto neigh:transpose[node])
        {
            if(!visited[neigh])
                revDFS(neigh,visited,transpose,count);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        //  Do Kosaraju's ALgo
        vector<bool> visited(n,false);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
           if(!visited[i])
           {
               dfs(i,visited,adj,st);
           }
        }
        
        vector<int> transpose[n];
        
        for(int i=0;i<n;i++)
        {
            visited[i] = false;
            for(auto neigh:adj[i])
            {
                transpose[neigh].push_back(i);
            }
        }
        int maxcnt = 0;
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if(visited[top] == false)
                {
                    int count = 0;
                    revDFS(top,visited,transpose,count);
                    // cout<<count<<endl;
                    maxcnt = max(maxcnt,count);
                }
        }
        
        return maxcnt >= 2 ? maxcnt : -1;
    }
};