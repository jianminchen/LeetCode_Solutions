class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>         path;
        
        sort(candidates.begin(), candidates.end());
        
        dfs(res, target, 0, path, candidates);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& res, int target, int begin, vector<int>& path, vector<int>& candidates)
    {
        if(target == 0)
        {
            res.push_back(path);
            return;
        }
        
        for(int i=begin; i<candidates.size(); ++i)
        {
            if(candidates[i]<=target)
            {
                path.push_back(candidates[i]);
                dfs(res, target-candidates[i], i, path, candidates);
                path.pop_back();
            }
        }
    }
};