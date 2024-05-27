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
    ListNode* rev(ListNode* head){
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
    ListNode* getKnode(ListNode *head, int k){
        k -= 1;
        
        while(head != NULL && k > 0){
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        bool flag = false;
        while(temp != NULL){
            ListNode* kth = getKnode(temp,k);
            // if kth node is NULL;
            if(kth == NULL){
                if(prevlast)prevlast->next = temp;
                flag = true;
                break;
            }
            ListNode* nextnode = kth->next;
            kth->next = NULL;
            rev(temp);
            if(temp == head){
                head = kth;
            }
            else{
                prevlast->next = kth;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};