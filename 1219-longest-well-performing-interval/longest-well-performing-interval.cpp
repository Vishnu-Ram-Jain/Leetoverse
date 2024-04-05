class Solution {
public:
    int longestWPI(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        int temp = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > 8)temp++;
            else temp--;
            if(temp > 0){
                ans = max(ans,i+1);
            }
            else{
                if(mp.find(temp-1) != mp.end()){
                    ans = max(ans,i-mp[temp-1]);
                }
                if(mp.find(temp) == mp.end()){
                    mp[temp] = i;
                }
            }
        }
        return ans;
    }
};