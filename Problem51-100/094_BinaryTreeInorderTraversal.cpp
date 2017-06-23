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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>             res;
        stack<TreeNode *>       nodeStk;
        TreeNode                *cur;
        map<TreeNode *, bool>   visitState;
        
        nodeStk.push(root);
        if(root)
        {
            cur = root;
        }
        else
        {
            return res;
        }
        
        while(!nodeStk.empty())
        {
            if(cur->left && (visitState.find(cur->left) == visitState.end()))
            {
                cur = cur->left;
                nodeStk.push(cur);
                continue;
            }
            else
            {
                cur = nodeStk.top();
                nodeStk.pop();
                res.push_back(cur->val);
                visitState[cur] = true;
            }
            
            if(cur->right && (visitState.find(cur->right) == visitState.end()))
            {
                cur = cur->right;
                nodeStk.push(cur);
            }
        }
        
        return res;
    }
};