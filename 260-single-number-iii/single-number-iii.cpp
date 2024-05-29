class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long xorr = 0;
        for(auto i : nums)xorr ^= i;

        long rightmost = ((xorr) & (xorr-1)) ^ xorr;

        int b1 = 0,b2 = 0;
        for(auto i : nums){
            if(i & rightmost)b1 = b1 ^ i;
            else b2 = b2 ^ i;
        }
        return {b1,b2};
    }
};