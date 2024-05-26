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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* temp=head;
        int n=0;
        while(temp != NULL){
            n++;
            temp=temp->next;
        }
        int mid=n/2;
        temp=head;
        for(int i=0;i<mid - 1;i++){
            temp=temp->next;
        }
        if(temp->next != NULL){
            ListNode* nextnode=temp->next->next;
            temp->next=nextnode;
            return head;
        }
        else{
            // delete(temp);
            head->next=NULL;
            return head;
        }
    }
};