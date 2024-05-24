class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = n*m-1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(mat[mid/m][mid%m] == target)return true;

            else if(mat[mid/m][mid%m] > target)e = mid-1;

            else s = mid+1;
        }
        return false;
    }
};