class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> exp = h;
        sort(exp.begin(),exp.end());
        int cnt = 0;
        int n = h.size();
        for(int i=0;i<n;i++){
            if(exp[i] != h[i])cnt++;
        }
        return cnt;

    }
};