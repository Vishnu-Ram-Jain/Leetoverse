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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempa = list1;
        ListNode* tempb = list1;
        // ListNode* curra = NULL;
        // ListNode* currb = NULL;
        ListNode* curr = list1;
        ListNode * prev = NULL;
        a -= 1;
        while(a != 0){
            tempa = tempa->next;
            a--;
        }
        b += 1;
        while(b != 0){
            tempb = tempb->next;
            b--;
        }
        ListNode* head = list2;
        ListNode* last = NULL;
        while(head != NULL){
            if(head->next == NULL)last = head;
            head = head->next;
        }
        tempa->next = NULL;
        tempa->next = list2;
        last->next = tempb;

        // currb->next = NULL;
        return list1;

    }
};