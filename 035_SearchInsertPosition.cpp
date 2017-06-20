class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator   it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end()) {
            return it-nums.begin();
        }
        else {
            return nums.size();
        }
    }
};