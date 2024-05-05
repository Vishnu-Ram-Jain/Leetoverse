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

    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* nextnode = node->next;

        while(nextnode != NULL){
            curr->val = nextnode->val;
            if(nextnode->next == NULL){
                break;
            }
            curr = curr->next;
            nextnode = nextnode->next;
        }
        curr->next = NULL;
    }
};