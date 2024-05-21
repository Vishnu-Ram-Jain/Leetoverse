class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        int i=0,j=1,k=0;
        while(k < n){
            if(nums[k] > 0){
                v[i] = nums[k];
                i+=2;
            }
            else{
                v[j] = nums[k];
                j+=2;
            }
            k++;
        }
        return v;
    }
};