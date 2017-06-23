/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int i;
    struct ListNode *behindM, *nodeN, *cur, *append, *removed;
    
    behindM = nodeN = append = removed = NULL;
    i = 0;
    if(n==1)
    {
        return head;
    }
    
    if(m>1)
    {
        behindM = head;
    }
    else
    {
        cur = head;
    }
    
    nodeN = head;
    
    while(i<m-2)
    {
        behindM = behindM->next;
        nodeN = nodeN->next;
        ++i;
    }
    
    while(i<n-1)
    {
        nodeN = nodeN->next;
        ++i;
    }
    if(behindM)
    {
        cur = behindM->next;
    }
    
    append = nodeN->next;
    nodeN->next = NULL;
    
    while(cur)
    {
        removed = cur;
        cur = cur->next;
        removed->next = append;
        append = removed;
    }
    
    if(!behindM)
    {
        head = nodeN;
    }
    else
    {
        behindM->next = nodeN;
    }
    
    return head;
}