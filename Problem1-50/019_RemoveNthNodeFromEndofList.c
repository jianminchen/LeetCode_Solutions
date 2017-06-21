/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
   struct ListNode  *remember = NULL,
                    *cur = NULL,
                    *removeOne = NULL;
   int i = 0;
   
   remember = NULL;
   cur = head;
   while(cur)
   {
       if(i<n)
       {
            i++;
       }
       else if(i == n)
       {
           remember = head;
           i++;
       }
       else
       {
           remember = remember->next;
           i++;
       }
       
       cur = cur->next;
   }
   
   if(i == n)
   {
       cur = head->next;
       head->next = NULL;
       free(head);
       return cur;
   }
   
   if(remember)
   {
       removeOne = remember->next;
       remember->next = removeOne->next;
       removeOne->next = NULL;
       free(removeOne);
   }
   
   return head;
}