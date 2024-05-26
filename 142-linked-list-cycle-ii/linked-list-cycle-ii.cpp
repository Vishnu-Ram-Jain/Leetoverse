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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tempfast = NULL;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL)fast = fast->next;
            slow = slow->next;
            
            if(fast == slow){
                tempfast = fast;
                break;
            }
        }
        if(fast == NULL)return NULL;
        
        slow = head;
        
        while(slow != tempfast){
            slow = slow->next;
            tempfast = tempfast->next;
        }
        
        return slow;
    }
};