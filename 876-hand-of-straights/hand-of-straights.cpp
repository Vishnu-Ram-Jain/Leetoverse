class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        int n = hand.size();
        for(auto &i : hand)mp[i]++;
        for(int i=0;i<n;i++){
            int val = hand[i];
            if(mp.find(val) == mp.end())continue;
            mp[val]--;
            if(mp[val] == 0)mp.erase(val);

            int cnt = 1;
            while(cnt < groupSize){
                val++;
                if(mp.find(val) != mp.end()){
                    mp[val]--;
                    if(mp[val] == 0)mp.erase(val);
                    cnt++;
                }
                else{
                    return false;
                }
            }
        }
        return mp.size() == 0;
    }
};