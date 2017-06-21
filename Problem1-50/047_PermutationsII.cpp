class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>         save;
        sort(nums.begin(), nums.end());
        genPermuteUnique(res, save, nums);
        return res;
    }
    
    void genPermuteUnique(vector<vector<int>>& res, vector<int>& save, vector<int>& nums)
    {
        if(nums.empty())
        {
            res.push_back(save);
            return;
        }
        
        for(int i=0; i<nums.size(); ++i)
        {
            int last = nums[i];
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }
            save.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            genPermuteUnique(res, save, nums);
            nums.insert(nums.begin()+i, last);
            save.pop_back();
        }
    }
};