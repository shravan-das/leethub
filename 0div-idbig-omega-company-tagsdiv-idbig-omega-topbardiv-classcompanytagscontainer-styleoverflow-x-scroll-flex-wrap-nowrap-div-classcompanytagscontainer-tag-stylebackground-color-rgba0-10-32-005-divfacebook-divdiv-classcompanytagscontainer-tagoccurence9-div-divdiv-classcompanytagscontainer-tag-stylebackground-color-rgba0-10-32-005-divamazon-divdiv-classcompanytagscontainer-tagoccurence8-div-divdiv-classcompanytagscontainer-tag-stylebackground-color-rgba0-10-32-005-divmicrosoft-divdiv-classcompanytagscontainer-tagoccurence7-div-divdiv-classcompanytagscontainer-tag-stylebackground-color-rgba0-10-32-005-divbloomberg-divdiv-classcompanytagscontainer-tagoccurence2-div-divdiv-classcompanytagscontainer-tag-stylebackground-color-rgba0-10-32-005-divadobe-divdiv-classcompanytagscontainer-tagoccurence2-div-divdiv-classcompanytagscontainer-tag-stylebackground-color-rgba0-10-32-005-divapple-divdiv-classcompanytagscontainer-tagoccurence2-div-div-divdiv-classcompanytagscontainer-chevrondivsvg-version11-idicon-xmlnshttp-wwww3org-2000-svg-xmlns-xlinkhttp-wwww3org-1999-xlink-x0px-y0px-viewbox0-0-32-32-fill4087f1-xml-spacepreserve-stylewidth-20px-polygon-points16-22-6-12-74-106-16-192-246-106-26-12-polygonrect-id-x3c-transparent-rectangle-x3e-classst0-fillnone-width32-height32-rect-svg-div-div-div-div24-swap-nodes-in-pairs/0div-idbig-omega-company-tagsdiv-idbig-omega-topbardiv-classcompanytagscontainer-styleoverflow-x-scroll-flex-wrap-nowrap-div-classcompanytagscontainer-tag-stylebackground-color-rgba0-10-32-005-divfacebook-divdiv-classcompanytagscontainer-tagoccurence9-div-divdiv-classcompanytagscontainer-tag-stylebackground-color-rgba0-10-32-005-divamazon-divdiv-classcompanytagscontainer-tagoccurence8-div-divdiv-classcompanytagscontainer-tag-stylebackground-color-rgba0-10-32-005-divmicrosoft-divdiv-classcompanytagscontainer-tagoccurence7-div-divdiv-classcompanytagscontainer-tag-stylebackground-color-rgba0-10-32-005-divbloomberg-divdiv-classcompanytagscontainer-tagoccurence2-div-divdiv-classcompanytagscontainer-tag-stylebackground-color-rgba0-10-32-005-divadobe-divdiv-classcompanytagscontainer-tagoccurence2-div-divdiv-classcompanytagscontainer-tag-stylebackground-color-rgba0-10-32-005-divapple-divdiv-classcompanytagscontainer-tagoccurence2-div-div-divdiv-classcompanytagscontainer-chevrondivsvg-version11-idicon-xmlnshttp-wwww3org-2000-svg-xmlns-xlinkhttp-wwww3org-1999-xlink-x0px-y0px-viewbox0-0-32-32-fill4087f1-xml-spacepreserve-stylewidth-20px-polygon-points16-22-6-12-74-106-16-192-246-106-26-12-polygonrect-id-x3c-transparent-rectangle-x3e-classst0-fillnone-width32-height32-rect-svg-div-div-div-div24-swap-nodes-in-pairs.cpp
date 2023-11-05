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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;
        while(current && current->next){
            ListNode *temp = current->next->next;
            ListNode *nex = current->next;
            nex->next = current;
            current->next = temp;
            
            prev->next = nex;
            prev = current;
            current = temp;
        }
        return dummy->next;
        
    }
};