class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums){
            if(i > 0)mp[i]++;
        }

        int num = 1;
        for(auto i : mp){
            if(i.first != num)return num;
            num++;
        }
        return num;
    }
};