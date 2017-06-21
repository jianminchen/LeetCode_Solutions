/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode **nodeStack;
    struct ListNode *cur, *left;
    int i;
    
    if(k == 1)
    {
        return head;
    }
    
    nodeStack = (struct ListNode **)malloc(k*sizeof(struct ListNode *));
    cur = head;
    
    i = k-1;
    
    while(i>=0 && cur)
    {
        nodeStack[i] = cur;
        cur = cur->next;
        i --;
    }
     
    if(i>=0)
    {
        free(nodeStack);
        return head;
    }
    
    head = cur = nodeStack[0];

    left = nodeStack[0]->next;
    for(i = 1; i<k ; i++)
    {
        cur->next = nodeStack[i];
        cur = cur->next;
    }
    
    free(nodeStack);
    cur->next = reverseKGroup(left, k);
    return head;
}