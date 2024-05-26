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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL)return head;
        ListNode* o = head;
        ListNode* e = head->next;
        ListNode* eh = e;

        while(e != NULL && e->next != NULL){
            o->next = o->next->next;
            e->next = e->next->next;

            o = o->next;
            e = e->next;
        }

        o->next = eh;

        return head;
    }
};