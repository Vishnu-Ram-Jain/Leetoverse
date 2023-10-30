class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int,int> > v;
        for(int i=0;i<arr.size();i++){
           int ct=0;
           int n=arr[i];
            while(n != 0){
                int bit=n&1;
                if(bit==1){
                    ct++;
                }
                n=n>>1;
            }
            v.push_back({ct,arr[i]});
        }

        sort(v.begin(),v.end());
        for(int i=0;i<arr.size();i++){
            ans.push_back(v[i].second);
        }

        return ans;
        
    }
};