class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>         path;
        
        sort(candidates.begin(), candidates.end());
        
        dfs(res, 0, candidates, path, target);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& res, int idx, vector<int>& candidates, vector<int>& path, int target)
    {
        if(target == 0)
        {
            res.push_back(path);
            return;
        }
        
        for(int i = idx; i<candidates.size(); ++i)
        {
            if(i>0 && candidates[i] == candidates[i-1])
            {
                continue;
            }
            if(target>=candidates[i])
            {
                int tmp;
                tmp = candidates[i];
                path.push_back(candidates[i]);
                candidates.erase(candidates.begin()+i);
            
                dfs(res, i, candidates, path, target-tmp);
                path.pop_back();
                candidates.insert(candidates.begin()+i, tmp);
            }
        }
    }
};