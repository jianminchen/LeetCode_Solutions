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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>                   res;
        //vector<vector<vector<TreeNode*>>>   DP(n, vector<vector<TreeNode*>>(n, vector<TreeNode*>));
        
        if(n==0)
        {
            return res;
        }
        
        res = genTrees(1, n);
        return res;
    }
    
    vector<TreeNode*> genTrees(int m, int n)
    {
        vector<TreeNode*>   res1, res2, res;
        int                 rSize1, rSize2, i, j, k;
        
        if(n<m)
        {
            res.push_back(NULL);
            return res;
        }
        
        if(n == m)
        {
            TreeNode *oneNode = new TreeNode(m);
            res.push_back(oneNode);
            return res;
        }
        
        for(k=m;k<=n; ++k)
        {
            res1 = genTrees(m, k-1);
            res2 = genTrees(k+1, n);
            rSize1 = res1.size();
            rSize2 = res2.size();
            for(i = 0; i<rSize1;++i)
            {
                for(j = 0; j<rSize2;++j)
                {
                    TreeNode *newNode = new TreeNode(k);
                    newNode->left = res1[i];
                    newNode->right = res2[j];
                    res.push_back(newNode);
                }
            }
        }
        
        return res;
    }
};