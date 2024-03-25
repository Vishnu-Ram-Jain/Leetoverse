class Solution {
public:
    int f(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            ans = max(ans,sum);
            if(sum < 0)sum = 0;
        }
        return ans;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mp;
        vector<int> arr(s.size(),0);
        for(int i=0;i<chars.size();i++){
            mp[chars[i]] = i;
        }

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                int ind = mp[s[i]];
                arr[i] = vals[ind];
            }
            else arr[i] = s[i] - 'a' + 1;
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;

        int ans = f(arr);
        return ans < 0 ? 0 : ans;
    }
};