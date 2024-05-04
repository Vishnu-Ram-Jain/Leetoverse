class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        int s=0;
        int e=people.size()-1;
        while(s<=e){
            ans++;
            if(people[s] + people[e] <= limit){
            s++;
            }
            e--;

        }
        return ans;
    }
};