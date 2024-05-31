class Solution {
public:
    int commonFactors(int a, int b) {
        unordered_map<int,bool> mp;
        for(int i=1;i*i<=a;i++){
            if(a % i == 0){
                mp[i] = 1;
                if(a/i != i)mp[a/i] = 1; 
            }
        }

        int cnt = 0;

        for(int i=1;i*i<=b;i++){
            if(b % i == 0){
                if(mp.find(i) != mp.end())cnt++;
                if(b/i != i)if(mp.find(b/i) != mp.end())cnt++; 
            }
        }

        return cnt;
    }
};