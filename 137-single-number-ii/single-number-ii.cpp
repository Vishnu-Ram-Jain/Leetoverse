class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> arr(32, 0);
        int ans = 0;
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < nums.size(); j++){
                arr[i] += (nums[j] & 1);
                nums[j] = nums[j] >> 1;
            }
        }
        for(int i = 0; i < 32; i++){
            arr[i] = arr[i] % 3;
            if(arr[i]){ 
                int mask = 1;
                mask = (mask << i);
                ans = ans | mask;
            }
        }
        return ans;
    }
};