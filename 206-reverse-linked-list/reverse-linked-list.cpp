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
    void f(ListNode* &head, ListNode* &prev){
        if(head == NULL)return ;

        ListNode* curr = head;
        ListNode* nextnode = NULL;

        if(curr != NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        f(nextnode,prev);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        f(head,prev);
        return prev;
    }
};