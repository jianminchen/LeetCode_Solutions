class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size()-1; ++i) {
            int next = target - nums[i];
            vector<int>::iterator it = find(nums.begin()+i+1, nums.end(), next);
            if(it != nums.end()) {
                int idx = it-nums.begin();
                return {i, idx};
            }
        }
        
        return vector<int>();
    }
};