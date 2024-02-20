class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;
        bool zero = false;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i] == 0){
                zero = true;
            }
        }
        
        int newsum=n*(n+1)/2;

        if(newsum - sum != 0){
            return newsum - sum;
        }
        else{
            if(zero)
            return n;
            else
            return 0;
        }
    }
};