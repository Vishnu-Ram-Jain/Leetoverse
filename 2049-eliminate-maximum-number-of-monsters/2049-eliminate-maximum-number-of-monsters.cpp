class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> v;
        int n = dist.size();
        for(int i=0;i<n;i++){
            float val = ((float)dist[i] / speed[i]);
            v.push_back(val);
        }

        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] <= i){
                break;
            }
            ans++;
        }
        return ans;
    }
};