class Solution {
public:
    void addcontributionJ(int num, vector<int> &bit){
        int i=0;
        while(num > 0){
            bit[i++] += num & 1;
            num = num>>1;
        }
    }
    void removecontributionI(int num, vector<int> &bit){
        int i=0;
        while(num > 0){
            bit[i++] -= num & 1;
            num = num>>1;
        }
    }
    bool good(vector<int> &bit){
        for(int i=0;i<32;i++){
            if(bit[i] > 1)return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),ans=0;
        vector<int> bit(32,0);

        for(j=0;j<n;j++){
            addcontributionJ(nums[j],bit);

            while(i < j && !good(bit)){
                removecontributionI(nums[i],bit);
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};