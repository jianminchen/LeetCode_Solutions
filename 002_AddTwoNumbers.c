/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void addNextTwo(struct ListNode *, struct ListNode *, struct ListNode *, int);
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
     int moreThanNine, num1, num2;
     struct ListNode *curL1, *curL2, *retList;
     
     moreThanNine = 0;
     
     curL1 = l1;
     curL2 = l2;
     retList = (struct ListNode *)malloc(sizeof(struct ListNode));
     if(curL1->val + curL2->val>9)
     {
         retList->val = curL1->val+curL2->val-10;
         moreThanNine = 1;
         retList->next = NULL;
     }
     else
     {
         retList->val = curL1->val+curL2->val;
         retList->next = NULL;
         moreThanNine = 0;
     }
     
     addNextTwo(retList, curL1->next, curL2->next, moreThanNine);
     
     return retList;
}

void
addNextTwo(struct ListNode *curList, struct ListNode *curL1, struct ListNode *curL2, int moreThanNine)
{
    int num1, num2;
    struct ListNode *nextL1, *nextL2;
    
    if((!curL1) &&(!curL2) && (!moreThanNine))
    {
        return;
    }
    
    num1 = curL1? curL1->val : 0;
    num2 = curL2? curL2->val : 0;
    nextL1 = curL1? curL1->next : NULL;
    nextL2 = curL2? curL2->next : NULL;
    
    curList->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    if(num1+num2+moreThanNine>9)
    {
        curList->next->val = num1+num2+moreThanNine - 10;
        moreThanNine = 1;
    }
    else
    {
        curList->next->val = num1+num2+moreThanNine;
        moreThanNine = 0;
    }
    
    curList->next->next = NULL;
    addNextTwo(curList->next, nextL1, nextL2, moreThanNine);
    return;
}