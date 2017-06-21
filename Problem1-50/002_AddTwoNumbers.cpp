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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode    *cur1 = l1,
                    *cur2 = l2;
        
        int add = 0;
        ListNode    *res = NULL,
                    *last = NULL;
        while(cur1 || cur2)
        {
            int num1 = 0,
                num2 = 0;
                
            if(cur1)
            {
                num1 = cur1->val;
                cur1 = cur1->next;
            }
            
            if(cur2)
            {
                num2 = cur2->val;
                cur2 = cur2->next;
            }
            
            ListNode *newNode = new ListNode((num1+num2+add)%10);
            add = (num1+num2+add)/10;
            
            if(res == NULL)
            {
                res = newNode;
                last = newNode;
            }
            else
            {
                last->next = newNode;
                last = last->next;
            }
        }
        
        if(add)
        {
            ListNode *addOne = new ListNode(add);
            last->next = addOne;
        }
        
        return res;
    }
};