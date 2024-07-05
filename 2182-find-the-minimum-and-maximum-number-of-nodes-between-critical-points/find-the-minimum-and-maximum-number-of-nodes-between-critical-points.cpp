/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        ListNode* prev = head;
        ListNode* next = NULL;
        ListNode* curr = head->next;
        int ind = 2;
        while(curr != NULL){
            next = curr->next;
            if(next != NULL){
                if(curr->val > prev->val && curr->val > next->val)v.push_back(ind);
            }
            if(next != NULL){
                if(curr->val < prev->val && curr->val < next->val)v.push_back(ind);
            }
            ind++;
            prev = curr;
            curr = curr->next;
        }
        if(v.size() < 2)return {-1,-1};
        sort(v.begin(),v.end());
        int mini = 1e9;
        int maxi = v[v.size()-1] - v[0];
        for(int i=0;i<v.size()-1;i++){
            // cout<<v[i]<<" ";
            mini = min(mini,abs(v[i]-v[i+1]));
        }
        return {mini,maxi};
    }
};