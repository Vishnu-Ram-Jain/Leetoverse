class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // sum,index;
        unordered_map<int,int> mp;
        int sum = 0, maxlen = 0;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i] == 0 ? -1 : 1);

            if(mp.find(sum) != mp.end()){
                maxlen = max(maxlen,i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return maxlen;
    }
};