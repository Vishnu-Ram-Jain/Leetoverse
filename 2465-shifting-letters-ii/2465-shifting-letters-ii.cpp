class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] < a[2];
        return a[0]<b[0];
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map<int,int>mp;
        int n = s.length();
        sort(shifts.begin(),shifts.end());
        for(auto r : shifts){
            int start = r[0];
            int end = r[1];
            int dir = r[2];
            if(dir == 1) {
                mp[start]++;
                mp[end+1]--;
            }
            else{
                mp[start]--;
                mp[end+1]++;
            }
        }

        string alphas = "abcdefghijklmnopqrstuvwxyz";
        int cnt = 0;

        for(int i=0; i<n; i++){
            cnt += mp[i];
            s[i] = alphas[((s[i]-'a') + cnt + 26*26*26*26)%26];
        }
        return s;
    }
};