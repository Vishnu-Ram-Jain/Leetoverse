class MapSum {
public:
    unordered_map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int tot = 0;
        for(auto it : mp){
            string s = it.first;
            bool fl = true;
            int temp = it.second;

            for(int i=0;i<prefix.size();i++){
                if(prefix[i] != s[i]){
                    fl = false;
                    break;
                }
            }

            if(fl)tot += temp;
        }
        return tot;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */