class Solution {
public:
    int leastInterval(vector<char>& t, int pd) {
        vector<int> freq(26,0);
        for(auto i : t){
            freq[i - 'A']++;
        }

        sort(freq.begin(),freq.end());
        int f = freq[25] - 1;
        int idle = f * pd;

        for(int i=24;i>=0;i--){
            idle -= min(freq[i],f);
        }

        return idle < 0 ? t.size() : t.size() + idle;
    }
};