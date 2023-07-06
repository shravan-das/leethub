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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k ==1){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        ListNode *pre = dummy;
        ListNode *temp = dummy;
        int count = 0;
        
        while(current->next!=NULL){
            current = current->next;
            count++;
        }
        while(count>=k){
            current = pre->next;
            temp = current->next;
            for( int i = 1 ; i<k;i++){
                current->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
                temp = current->next;
            }
            pre = current;
            count = count - k;
        }
        
        return dummy->next;
        
        
    }
};