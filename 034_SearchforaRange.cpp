class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator   it1,
                                it2;
        vector<int>             res;
        it1 = lower_bound(nums.begin(), nums.end(), target);
        it2 = upper_bound(nums.begin(), nums.end(), target);
        
        if(it1 != nums.end() && *it1 == target) {
            res.push_back((int)(it1-nums.begin()));
            --it2;
            res.push_back((int)(it2-nums.begin()));
            return res;
        }
        else {
            res = {-1,-1};
            return res;
        }
    }
};