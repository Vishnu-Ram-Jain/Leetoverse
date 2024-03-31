class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int totsum = 0;
        for(auto i : possible){
            totsum += (i == 1) ? 1 : -1; 
        }
        int pre = 0;
        for(int i=0;i<possible.size()-1;i++){
            pre += (possible[i] == 1) ? 1 : -1;
            int remsum = totsum - pre;
            if(pre > remsum)return i+1;
        }
        return -1;
    }
};