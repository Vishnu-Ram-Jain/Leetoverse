class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0, j = n-1;
        while(i < j){
            if(nums[i] == 0 and nums[j] == 0)i++;
            else if(nums[i] != 0 and nums[j] != 0)j--;
            else if(nums[i] != 0 and nums[j] == 0){
                swap(nums[i++],nums[j--]);
            }
            else if(nums[i] == 0 and nums[j] != 0)i++;
        }

        i = 0;
        while(i < n and nums[i] == 0){
            i++;
        }
        j = n-1;
        while(i < j){
            if(nums[i] == 1 and nums[j] == 1)i++;
            else if(nums[i] != 1 and nums[j] != 1)j--;
            else if(nums[i] != 1 and nums[j] == 1){
                swap(nums[i++],nums[j--]);
            }
            else if(nums[i] == 1 and nums[j] != 1)i++;
        }
    }
};