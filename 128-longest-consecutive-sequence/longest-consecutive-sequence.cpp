class Solution {
public:
    typedef long long ll;
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxlen = 1;
        int currlen = 0;
        ll lastsmallest = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] - lastsmallest == 1){
                currlen++;
                lastsmallest = nums[i];
            }
            else if(nums[i] != lastsmallest) {
                lastsmallest = nums[i];
                currlen = 1;
            }
            maxlen = max(maxlen,currlen);
        }
        return maxlen;
    }
};