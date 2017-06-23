class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>         save;
        int                 i;
        
        sort(nums.begin(), nums.end());
        if(nums.size() == 0)
        {
            res.push_back(save);
            return res;
        }
        
        while(nums.size())
        {
            int dupLen = 0;
            int storeR0 = nums[nums.size()-1];
            
            i = nums.size()-1;
            
            while(i>=0 && nums[i] == storeR0)
            {
                ++dupLen;
                nums.pop_back();
                --i;
            }
            
            res = subsetsWithDup(nums);
            int resSize = res.size();
            
            for(int m = 1; m<=dupLen;++m)
            {
                for(int j = 0; j<resSize; ++j)
                {
                    save = res[j];
                    for(int k = 1; k<=m;++k)
                    {
                        save.push_back(storeR0);
                    }
                    res.push_back(save);
                }
            }
        }
        return res;
    }
};