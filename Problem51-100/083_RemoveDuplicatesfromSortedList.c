/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *cur, *storeR0;
    
    if(!head || !head->next)
    {
        return head;
    }
    
    storeR0 = cur = head;
    while(cur)
    {
        if(cur->val != storeR0->val)
        {
            storeR0->next = cur;
            storeR0 = cur;
            cur = cur->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    storeR0->next = NULL;
    return head;
}