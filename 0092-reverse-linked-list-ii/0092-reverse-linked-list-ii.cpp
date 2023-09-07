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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy;
        if(left==right){
         return dummy->next;
        }
        int k = 0;
        if(left>1){
         while(start!=NULL && start->next!=NULL && k!=left-1){
             start = start->next;
             k++;
         }   
        }
        ListNode *current = start->next;
        ListNode *prev = NULL;
        ListNode *temp;
        int count = 0;
        int dif = right-left;
        while(current!=NULL && count<=dif){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            count++;
            
        }
        start->next = prev;
        int rightcounter = 1;
        ListNode *rightnode = dummy->next;
        while(rightnode && rightnode->next && rightcounter!=right){
            rightnode = rightnode->next;
            
        }
        rightnode->next = current;
        if(rightnode->next==NULL){
            return dummy->next;
        }
        
        
        return dummy->next;
        
        
    }
};