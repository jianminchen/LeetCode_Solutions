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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return head;
        }
        
        ListNode    *cur = head,
                    *last = NULL;
        stack<ListNode*>    nodeStk;
        int num = 0;
        while(cur && num<k)
        {
            nodeStk.push(cur);
            ++num;
            cur = cur->next;
        }
        
        if(nodeStk.size()<k)
        {
            return head;
        }
        
        head = nodeStk.top();
        nodeStk.pop();
        last = head;
        while(!nodeStk.empty())
        {
            last->next = nodeStk.top();
            nodeStk.pop();
            last = last->next;
        }
        
        last->next = reverseKGroup(cur, k);
        return head;
    }
};