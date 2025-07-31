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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
        return head;
        ListNode *fast=head;
        ListNode *slow=head;

        // while(fast && slow &&fast->next && slow->next)
        // {
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(fast==slow)
        //     return true;
        // }
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow==fast ){
                return true;
            }
        }
        return false   ;  
    }
};