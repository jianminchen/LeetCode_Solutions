class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return 0;
        }
        return jumpFast(nums, 0);
    }
    
    int jumpFast(vector<int>& nums, int idx)
    {
        if(idx+nums[idx]>=nums.size()-1)
        {
            return 1;
        }
        
        int curMax = 0,
            next = idx;
        for(int i = idx+1; i<=idx+nums[idx]; ++i)
        {
            if(i+nums[i]>curMax)
            {
                next = i;
                curMax = i+nums[i];
            }
        }
        
        return 1+jumpFast(nums, next);
    }
};