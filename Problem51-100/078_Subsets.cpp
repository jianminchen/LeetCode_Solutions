class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>     res;
        int                     tmp, resSize;
        
        if(nums.size()==0)
        {
            vector<int> save;
            res.push_back(save);
            return res;
        }
        
        tmp = nums[nums.size()-1];
        nums.pop_back();
        res = subsets(nums);
        resSize = res.size();
        
        for(int i=0; i<resSize;++i)
        {
            vector<int> newSet = res[i];
            newSet.push_back(tmp);
            res.push_back(newSet);
        }
        return res;
    }
};