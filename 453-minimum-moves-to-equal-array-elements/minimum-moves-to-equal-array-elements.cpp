class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int sum = 0;

        for(int i=0;i<n;i++){
            if(nums[i] != mini){
                sum += (nums[i] - mini);
            }
        }
        return sum;
    }
};