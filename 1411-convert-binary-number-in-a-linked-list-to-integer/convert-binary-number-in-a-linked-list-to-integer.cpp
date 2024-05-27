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
        if(head == NULL || head->next == NULL)return head;
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
    int getDecimalValue(ListNode* head) {
        head = rev(head);
        ListNode* temp = head;
        int i=0;
        int ans = 0;

        while(temp != NULL){
            if(temp->val != 0){
                ans = ans + pow(2,i);
            }
            i++;
            temp = temp->next;
        }
        return ans;
    }
};