/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *second;
    
    if(!head || !head->next)
    {
        return head;
    }
    
    second = head->next;
    head->next = second->next;
    second->next = head;
    second->next->next = swapPairs(second->next->next);
    
    return second;
}