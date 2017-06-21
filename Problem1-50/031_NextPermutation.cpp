class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size()-1,
            i = 0,
            ex = 0,
            least = 0;
        
        while(idx && nums[idx] <= nums[idx - 1])
        {
            --idx;
        }
        
        if(!idx)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        
        least = INT_MAX;
        ex = INT_MAX;
        
        for(i = nums.size()-1; i> idx-1; i--)
        {
            if(nums[i]>nums[idx-1] && (nums[i] - nums[idx-1])<least)
            {
                ex = i;
                least = nums[ex] - nums[idx-1];
            }
        }
        
        swap(nums[idx-1], nums[ex]);
        sort(nums.begin() + idx, nums.end());
    }
};