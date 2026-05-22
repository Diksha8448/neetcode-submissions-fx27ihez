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
    void reorderList(ListNode* head) {
        // we will check if head is not null or its not only one element
        if(!head ||!head->next){
            return;
        }

        // 1. find the middle  slow pointer fast pointer

        ListNode* slow=head;
        ListNode* fast=head;
        // Using fast->next && fast->next->next gives the left-middle node, 
        //which helps split the list evenly for reordering.
        while(fast->next &&fast->next->next){
          slow=slow->next;
          fast=fast->next->next;
        }
        
        // 2. reverse the second half 
        ListNode*second=slow->next;
        slow->next=NULL;

        ListNode* prev=NULL;

        while(second){
             ListNode* temp = second->next;

            second->next = prev;

            prev = second;

            second = temp;
        } 
        // STEP 3: merge two halves
        ListNode* first = head;
        second = prev;

        while (second) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;

            second->next = temp1;

            first = temp1;
            second = temp2;
        }

    }
};
