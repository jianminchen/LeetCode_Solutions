/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *cur = NULL,
                    *cmp = NULL,
                    *head = NULL,
                    *last = NULL;
    
    if(!l1)
    {
        return l2;
    }
    else if(!l2)
    {
        return l1;
    }
    
    head = l1->val>l2->val?l2:l1;
    cmp = l1->val>l2->val?l1:l2;
    cur = head->next;
    last = head;
    while(cur)
    {
        if(cur->val <= cmp->val)
        {
            cur=cur->next;
            last = last->next;
        }
        else
        {
            last->next = cmp;
            cmp = cur;
            last = last->next;
            cur = last->next;
        }
    }
    
    last->next = cmp;
    
    return head;
}