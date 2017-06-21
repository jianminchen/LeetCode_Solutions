class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>     res;
        vector<int>             save;
        
        if(n<k)
        {
            return res;
        }

        genCombine(res, 1, n, save, k);
        
        return res;
    }
    
    void genCombine(vector<vector<int>>& res, int begin, int end, vector<int>& save, int k)
    {
        int tmp;
        
        if(!k)
        {
            res.push_back(save);
            return;
        }
        
        for(int i=begin; i<=end; ++i)
        {
            save.push_back(i);
            genCombine(res, i+1, end, save, k-1);
            save.pop_back();
        }
    }
};