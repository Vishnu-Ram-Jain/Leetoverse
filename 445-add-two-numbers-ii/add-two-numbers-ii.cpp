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
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;

        while(head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);

        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* nh = dummy;
        int c = 0;
        while(p != NULL && q != NULL){
            int sum = p->val + q->val + c;
            int val = sum % 10;
            ListNode* node = new ListNode(val);
            dummy->next = node;
            dummy = dummy->next;
            c = sum / 10;
            p = p->next;
            q = q->next;
        }

        while(p != NULL){
            int sum = p->val + c;
            int val = sum % 10;
            ListNode* node = new ListNode(val);
            dummy->next = node;
            dummy = dummy->next;
            c = sum / 10;
            p = p->next;
        }
        while(q != NULL){
            int sum = q->val + c;
            int val = sum % 10;
            ListNode* node = new ListNode(val);
            dummy->next = node;
            dummy = dummy->next;
            c = sum / 10;
            q = q->next;
        }

        if(c > 0){
            ListNode* node = new ListNode(c);
            dummy->next = node;
            dummy = dummy->next;
        }

        return rev(nh->next);

    }
};