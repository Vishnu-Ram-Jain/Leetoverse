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
    ListNode* rev(ListNode* head, ListNode* tail){
        if(head == NULL or head->next == NULL)return head;
        ListNode* prev = NULL;
        ListNode* nextnode = NULL;
        ListNode* curr = head;

        while(curr != tail){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr = head;
        ListNode* dummy = new ListNode(-1);

        ListNode* tail = head;
        while(right > 0){
            tail = tail->next;
            right--;
        }
        if(left == 1){
            dummy->next = head;
            dummy->next = rev(dummy->next,tail);
            ListNode* temp = dummy;
            while(temp->next != NULL)temp = temp->next;
            temp->next = tail;
            return dummy->next;
        }
        else if(left > 1){
            left -= 2;
            while(left > 0){
                ptr = ptr->next;
                left--;
            }
        }

        ptr->next = rev(ptr->next,tail);
        ListNode* temp = ptr;
        while(temp->next != NULL)temp = temp->next;
        temp->next = tail;

        return head;
    }
};