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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode            *cur = head,
                            *rmNode = NULL;
        stack<ListNode *>   nodeStk;
        
        while(cur)
        {
            nodeStk.push(cur);
            cur = cur->next;
        }
        
        while(n && !nodeStk.empty())
        {
            nodeStk.pop();
            --n;
        }
        if(!nodeStk.empty())
        {
            cur = nodeStk.top();
            rmNode = cur->next;
            cur->next = rmNode->next;
        }
        else
        {
            rmNode = head;
            head = head->next;
        }
        
        rmNode->next = NULL;
        delete rmNode;
        rmNode = NULL;
        return head;
    }
};