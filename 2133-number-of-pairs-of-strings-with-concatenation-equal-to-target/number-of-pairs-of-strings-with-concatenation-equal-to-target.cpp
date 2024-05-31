class Solution {
public:
    int numOfPairs(vector<string>& nums, string tar) {
        unordered_map<string,int> mp;
        unordered_map<string,bool> vis;
        int cnt = 0;
        for(auto it : nums){
            mp[it]++;
        }

        int tarlen = tar.size();
        for(auto  it : nums){
            string left = it;
            int len = left.size();
            if(len > tarlen)continue;
            string right = tar.substr(len,tarlen);
            if(mp.find(right) != mp.end() && left + right == tar){
                // cout<<right<<endl;
                if(left == right)cnt += mp[right] - 1;
                else cnt += mp[right];
                // cout<<mp[right]<<endl;
            }
            
            // vis[left] = 1;
        }
        return cnt;
    }
};