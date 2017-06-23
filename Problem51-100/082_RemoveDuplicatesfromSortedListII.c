/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *cur, *lastDistinct, *last;
    
    lastDistinct = NULL;
    
    if(!head || !head->next)
    {
        return head;
    }
    
    if(head->val != head->next->val)
    {
        lastDistinct = head;
    }
    else if(!head->next->next)
    {
        return NULL;
    }
    
    last = head;
    cur = head->next;
    
    while(cur->next)
    {
        if(cur->val != last->val 
            && cur->val != cur->next->val)
        {
            if(!lastDistinct)
            {
                head = lastDistinct = cur;
            }
            else
            {
                lastDistinct->next = cur;
                lastDistinct = lastDistinct->next;
            }
            last = cur;
            cur = cur->next;
        }
        else
        {
            last = last->next;
            cur = cur->next;
        }
    }
    
    if(last->val != cur->val)
    {
        if(!lastDistinct)
        {
            return cur;
        }
        else
        {
            lastDistinct->next = cur;
            lastDistinct = lastDistinct->next;
        }
    }
    
    if(!lastDistinct)
    {
        return NULL;
    }
    
    lastDistinct->next = NULL;
    return head;
}