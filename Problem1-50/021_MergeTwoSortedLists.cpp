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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode    *cur = NULL,
                    *cmp = NULL,
                    *last = NULL,
                    *head = NULL;
                    
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        head = l1->val<l2->val?l1:l2;
        cmp = l1->val<l2->val?l2:l1;
        last = head;
        cur = head->next;
        while(cur)
        {
            if(cur->val<=cmp->val)
            {
                cur = cur->next;
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
};