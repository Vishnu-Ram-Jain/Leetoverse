/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* t = head;
        while(t != NULL){
            if(t->val == 1e6)return true;
            t->val = 1e6;
            t = t->next;
        }
        delete(t);
        return false;
    }
};