/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int begin, i;
    struct ListNode *cur, *behind, *ret;
    
    if(!k || !head)
    {
        return head;
    }
    
    begin = i = 0;
    cur = behind = head;
    
    while(i<k && cur->next)
    {
        cur = cur->next;
        ++i;
    }
    
    if(i<k)
    {
        return rotateRight(head, k%(i+1));
    }
    
    while(cur->next)
    {
        cur = cur->next;
        behind = behind->next;
    }
    
    ret = behind->next;
    behind->next = NULL;
    cur->next = head;
    
    return ret;
}