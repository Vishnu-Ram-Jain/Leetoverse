class Solution {
public:
    bool haveConflict(vector<string>& a1, vector<string>& a2) {
        if(a2[0] <= a1[1] && a2[1] >= a1[0])return true;

        return false;
    }
};