/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        map<TreeNode *, bool>   stateMap;
        stack<TreeNode *>       nodeStk;
        TreeNode                *cur;
        int                      cmpVal;
        
        if(root)
        {
            nodeStk.push(root);
            cur = root;
        }
        
        while(!nodeStk.empty())
        {
            if(cur->left &&
                (stateMap.find(cur->left) == stateMap.end()))
            {
                cur = cur->left;
                nodeStk.push(cur);
                continue;
            }
            else
            {
                cur = nodeStk.top();
                nodeStk.pop();
                if(stateMap.size()==0 || cmpVal<cur->val)
                {
                    cmpVal = cur->val;
                }
                else
                {
                    return false;
                }
                
                stateMap[cur] = true;
            }
            
            if(cur->right && 
                (stateMap.find(cur->right)==stateMap.end()))
            {
                cur = cur->right;
                nodeStk.push(cur);
            }
        }
        return true;
    }
};