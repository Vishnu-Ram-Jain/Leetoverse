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
    ListNode* middleNode(ListNode* head) {
        // ListNode* temp = head;
        // int len = 0;
        // while(temp != NULL){
        //     len++;
        //     temp = temp->next;
        // }
        // len /= 2;
        // temp = head;
        // while(len--){
        //     temp = temp->next;
        // }
        // return temp;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL)fast = fast->next;
        }
        return slow;
    }
};