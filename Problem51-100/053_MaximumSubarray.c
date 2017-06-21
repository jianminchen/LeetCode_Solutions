int maxSubArray(int* nums, int numsSize) {
    int curSum = 0,
        retMax = nums[0],
        curMax = nums[0];
    
    for(int i = 0; i<numsSize; ++i)
    {
        
        if(curSum == 0 && nums[i]<0)
        {
            curMax = nums[i];
        }
        else if(curSum == 0 && nums[i]>=0)
        {
            curSum += nums[i];
            curMax = curSum;
        }
        else if(curSum+nums[i]<=0)
        {
            curSum = 0;
            curMax = 0;
        }
        else
        {
            curSum += nums[i];
            curMax = curSum>curMax?curSum:curMax;
        }
        
        retMax = curMax>retMax?curMax:retMax;
    }
    
    return retMax;
}