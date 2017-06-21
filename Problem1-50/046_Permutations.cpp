class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>         save;
        
        genPermute(res, save, nums);
        
        return res;
    }
    
    void genPermute(vector<vector<int>>& res, vector<int>& save, vector<int>& nums)
    {
        if(nums.empty())
        {
            res.push_back(save);
            return;
        }
        
        for(int i=0; i<nums.size(); ++i)
        {
            int last = nums[i];
            
            save.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            genPermute(res, save, nums);
            save.pop_back();
            nums.insert(nums.begin()+i, last);
        }
    }
};