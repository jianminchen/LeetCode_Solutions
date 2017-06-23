/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *curLarger, *curLess, *less, *larger, *cur;
    curLarger = larger = NULL;
    curLess = less = NULL;
    
    if(!head || !head->next)
    {
        return head;
    }
    cur = head;
    
    while(cur)
    {
        if(cur->val<x)
        {
            if(!less)
            {
                curLess = less = cur;
            }
            else
            {
                curLess->next = cur;
                curLess = curLess->next;
            }
        }
        else
        {
            if(!larger)
            {
                curLarger = larger = cur;
            }
            else
            {
                curLarger->next = cur;
                curLarger = curLarger->next;
            }
        }
        
        cur = cur->next;
    }
    
    if(!less)
    {
        return larger;
    }
    
    curLess->next = larger;
    if(curLarger)
    {
        curLarger->next = NULL;
    }
    return less;
}