class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& supp) {
        unordered_map<string,vector<string>> adj; // this si for Adj. List
        unordered_map<string,int> ind; // this is for indegree count;
        unordered_map<string,bool> mm; 

        for(auto it : supp)mm[it] = 1;

        for(auto it : r)ind[it] = 0;

        // bool f=0;
        for(int i=0;i<r.size();i++){
            vector<string> temp = ing[i];

            for(int j=0;j<temp.size();j++){

                if(mm.find(temp[j]) == mm.end()){
                    // f=1;
                    adj[temp[j]].push_back(r[i]);
                    ind[r[i]]++;
                }

            }
        }
        // cout<<f<<endl;
        // for(auto it : r){
        //     for(auto i : adj[it]){
        //         ind[i]++;
        //     }
        // }
        queue<string> q;
        vector<string> v;
        for(auto it : ind){
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second == 0)q.push(it.first);
        }
        while(!q.empty()){
            string s = q.front();
            q.pop();
            v.push_back(s);
            for(auto it : adj[s]){
                ind[it]--;
                if(ind[it] == 0)q.push(it);
            }
        }
        return v;

    }
};