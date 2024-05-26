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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        unordered_map<ListNode*,bool> mp;
        ListNode* temp = head1;
        while(temp != NULL){
            mp[temp] = 1;
            temp = temp->next;
        }
        
        temp = head2;
        
        while(temp != NULL){
            if(mp[temp] == 1)return temp;
            temp = temp->next;
        }
        return NULL;
    }
};