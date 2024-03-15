class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        vector<int> v(n,0);
        int cnt = 0;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)prod *= nums[i];
            else{
                cnt++;
                ind = i;
            }
        }
        if(cnt > 1)return v;
        if(cnt == 1){
            v[ind] = prod;
            return v;
        }
        for(int i=0;i<n;i++){
            v[i] = prod / nums[i];
        }
        return v;
    }
};