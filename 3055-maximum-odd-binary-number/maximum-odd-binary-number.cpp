class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        int n = s.length();
        for(int i=0;i<s.length();i++){
            if(s[i] == '1')one++;
        }
        vector<int> v(n,0);
        v[n-1] = 1;
        one--;
        for(int i=0;i<n;i++){
            if(one != 0){
                v[i] = 1;
                one--;
            }
        }
        string ans;
        for(auto it : v){
            ans.push_back(it + '0');
        }
        return ans;
        
        
    }
};