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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextnode = NULL;

        while(curr != NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* newhead = dummy;
        int carry = 0;
        while(temp != NULL){
            int t = temp->val*2;
            int val = (t + carry) % 10;
            ListNode* node = new ListNode(val);
            dummy->next = node;
            carry = t / 10;
            temp = temp->next;
            dummy = dummy->next;
        }
        if(carry != 0){
           ListNode* node = new ListNode(carry);
           dummy->next = node; 
        }

        ListNode* ans = newhead;
        newhead = newhead->next;
        delete(ans);
        newhead = reverseList(newhead);
        return newhead;
    }
};