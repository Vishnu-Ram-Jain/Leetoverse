class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        sort(deck.begin(),deck.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int ind = q.front();
            q.pop();
            ans[ind] = deck[i];

            if(q.size() != 0){
                int index = q.front();
                q.pop();
                q.push(index);
            }
        }
        return ans;
        
    }
};