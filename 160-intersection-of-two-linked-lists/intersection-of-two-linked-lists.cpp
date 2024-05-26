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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        int len1 = 0, len2 = 0;
        while(temp != NULL){
            len1++;
            temp = temp->next;
        }

        temp = headB;

        while(temp != NULL){
            len2++;
            temp = temp->next;
        }

        if(len1 > len2){
            int bal = len1 - len2;
            // temp = headA;
            while(bal != 0){
                headA = headA->next;
                bal--;
            }
        }
        else{
            int bal = len2 - len1;
            while(bal != 0){
                headB = headB->next;
                bal--;
            }
        }

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};