class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0,j = 0, ans = 1, merge = nums[0];
        int n = nums.size();
        for(j = 1;j<n;j++){

            while((merge & nums[j]) != 0){
                merge = merge ^ nums[i];
                i++;
            }
            merge = merge | nums[j];
            ans = max(ans,(j-i+1));
        }
        return ans;
        
    }
};