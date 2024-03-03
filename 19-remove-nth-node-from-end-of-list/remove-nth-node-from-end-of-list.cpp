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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        if(head == NULL || head->next == NULL && n==1){
            return NULL;
        } 

        ListNode* temp=head;
        while(temp != NULL){
            size++;
            temp=temp->next;
        }

        int ct=size-n;
                if(ct == 0){
            return head->next;
        }
        ListNode* curr=head;
        for(int i=0;i<ct -1;i++){
            curr=curr->next;
        }
       
        if(curr->next != NULL){
        ListNode* nextnode=curr->next->next;
        ListNode* toDelete=curr->next;
        delete(toDelete);
        curr->next=nextnode;
        return head;
        }
       else{
           return NULL;
       }
        
    }
};