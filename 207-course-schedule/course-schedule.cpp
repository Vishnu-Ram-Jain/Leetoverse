class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        if(n == 0)return true;
        vector<int> adj[numCourses+1];
        for(int i=0;i<n;i++){
            int u = pre[i][1];
            int v = pre[i][0];

            adj[u].push_back(v);
        }

    	vector<int> indegree(numCourses,0);
	    
	    for(int i=0;i<numCourses;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    
	    for(int i=0;i<numCourses;i++){
	        if(indegree[i] == 0)q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0)q.push(it);
	        }
	    }
        return ans.size() == numCourses ? true : false;
    }
};