/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    struct TreeNode    *cur, *prev, *last, *first, *second;
    int         tmp;
    
    cur = root;
    prev = last = first = second = NULL;
    
    while(cur)
    {
        if(!cur->left)
        {
            if(last && last->val>cur->val)
            {
                if(!first)
                {
                    first = last;
                }
                second = cur;
            }
            last = cur;
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while(prev->right && prev->right != cur)
            {
                prev = prev->right;
            }
            
            if(!prev->right)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                if(last && last->val>cur->val)
                {
                    if(!first)
                    {
                        first = last;
                    }
                    second = cur;
                }
                last = cur;
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    
    tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}