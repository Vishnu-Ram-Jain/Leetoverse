class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> v;
        int ind = n-k;
        while(ind < n){
            v.push_back(nums[ind++]);
        }
        int j = 0;
        while(j <= ind-1){
            v.push_back(nums[j++]);
        }
        for(int i=0;i<n;i++)nums[i] = v[i];
    }
};