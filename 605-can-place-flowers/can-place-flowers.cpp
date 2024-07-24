class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int m = nums.size();
        if(n == 0)return true;
        if(n > m)return false;
        if(m == 1 && nums[0] == 0)return true;
        if(m == 1 && nums[0] == 1)return false;
        for(int i=0;i<m;i++){
            if(nums[i] == 1)continue;

            if(i==0){
                if(nums[i+1] != 1){
                    nums[i] = 1;
                    n--;
                    if(n == 0)return true;
                }
            }
            else if(i > 0 && i < m-1){
                if(nums[i-1] != 1 && nums[i+1] != 1){
                    nums[i] = 1;
                    n--;
                    if(n == 0)return true;
                }
            }
            else if(i == m-1){
                if(nums[i-1] != 1){
                    nums[i] = 1;
                    n--;
                    if(n == 0)return true;
                }
            }
        }
        return false;
    }
};