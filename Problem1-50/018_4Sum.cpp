class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int>>>  sumMap;
        vector<vector<int>>         res;
        set<vector<int>>            covered;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<nums.size(); ++i)
        {
            for(int j = i+1; j<nums.size(); ++j)
            {
                sumMap[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }
        
        for(auto sum : sumMap)
        {
            vector<pair<int, int>>  v1 = sum.second;
            if(sumMap.find(target-sum.first) != sumMap.end())
            {
                vector<pair<int, int>>  v2 = sumMap[target-sum.first];
                for(auto m1 : v1)
                {
                    for(auto m2 : v2)
                    {
                        if(m1.second < m2.first)
                        {
                            vector<int> tmp = {nums[m1.first], nums[m1.second], nums[m2.first], nums[m2.second]};
                            if(!covered.count(tmp))
                            {
                                covered.insert(tmp);
                                res.push_back(tmp);
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};