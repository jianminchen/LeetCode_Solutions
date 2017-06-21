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
    ListNode* rotateRight(ListNode* head, int k) {
        deque<ListNode *>   nodeQ;
        ListNode            *cur = head;
        if(k == 0 || !head) {
            return head;
        }
        
        while(cur) {
            if(nodeQ.size()<k+1) {
                nodeQ.push_back(cur);
            }
            else {
                nodeQ.pop_front();
                nodeQ.push_back(cur);
            }
            cur = cur->next;
        }
        
        if(nodeQ.size()<k+1) {
            int len = nodeQ.size();
            k = k%len;
            if(k == 0) {
                return head;
            }
            
            while(nodeQ.size()>k+1) {
                nodeQ.pop_front();
            }
        }
        nodeQ.back()->next = head;
        head = nodeQ.front()->next;
        nodeQ.front()->next = NULL;
        return head;
    }
};