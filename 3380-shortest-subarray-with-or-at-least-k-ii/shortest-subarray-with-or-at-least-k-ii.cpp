class Solution {
public:
    void addcontributionofJ(int number, vector<int> &bit){
        int num = number;
        int i=0;
        while(num > 0){
            int b  = num % 2;
            if(b==1)bit[i]++;
            i++;
            num /= 2;
            // bit[i] = bit[i] + 1 * (num%2);
            // i++;
            // num /=2;
        }
    }
    void removecontributionI(int number, vector<int> &bit){
        int num = number;
        int i=0;
        while(num > 0){
            int b  = num % 2;
            if(b==1)bit[i]--;
            i++;
            num /= 2;
            // bit[i] = bit[i] - 1 * (num%2);
            // i++;
            // num /=2;
        }
    }
    int formNumber(vector<int> &bit){
        int num = 0;
        int j = 0;
        for(int i=0;i<32;i++){
            if(bit[i] > 0)num = (1 * pow(2,j)) + num;
            j++;
            // num += (bit[i] ? 1 : 0) * pow(2,i);
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),ans=INT_MAX;

        vector<int> bit(32,0);

        for(j=0;j<n;j++){
            addcontributionofJ(nums[j],bit);

            while(formNumber(bit) >= k && i <= j){
                ans = min(ans,(j-i+1));
                removecontributionI(nums[i],bit);
                i++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};