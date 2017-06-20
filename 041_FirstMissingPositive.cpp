class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0,
            end = nums.size();
        if(nums.size() == 0) {
            return 1;
        }
        
        while(i<end) {
            if(nums[i] == i+1) {
                ++i;
            }
            else if(nums[i]<=0 || nums[i] == nums[nums[i]-1] || nums[i]>nums.size()) {
                swap(nums[i], nums[end-1]);
                --end;
            }
            else {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        return end+1;
    }
};