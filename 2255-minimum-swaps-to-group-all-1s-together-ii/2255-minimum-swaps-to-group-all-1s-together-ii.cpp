class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        int zero = 0;
        for(auto it : nums){
            if(it == 1)one++;
        }

        int i = 0, j = 0, ans = INT_MAX;

        for(j = 0;j<2*n;j++){
            if(nums[j%n] == 0)zero++;

            while((j-i+1) > one){
                if(nums[i%n] == 0)zero--;
                i++;
            }
            if((j-i+1) == one)ans = min(ans,zero);
        }

        return ans;
    }
};