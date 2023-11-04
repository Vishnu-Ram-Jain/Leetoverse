class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mx = INT_MIN;
        int x = left.size();
        int y = right.size();
        for(int i=0;i<x;i++){
            int val = abs(left[i] - 0);
            mx = max(mx,val);
        }
        for(int i=0;i<y;i++){
            int val = abs(right[i] - n);
            mx = max(mx,val);
        }
        return mx;
    }
};