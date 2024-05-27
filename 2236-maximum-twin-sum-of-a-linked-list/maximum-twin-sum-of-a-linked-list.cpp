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
    int pairSum(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        temp = head;
        int j = 0;
        int maxi = -1;
        while(temp != NULL){
            int i = n-1-j;
            if(mp.find(i) != mp.end()){
                maxi = max(maxi,mp[i]->val+temp->val);
                mp.erase(i);
            }
            mp[j] = temp;
            temp = temp->next;
            j++;
        }
        return maxi;
    }
};