int
searchFast(int *nums, int begin, int numsSize)
{
    int i = 0,
        nextStep = 0,
        curMax = 0;
    
    if(begin>= numsSize-1)
    {
        return 0;
    }
    
    if(begin+nums[begin]>=numsSize-1)
    {
        return 1;
    }
    
    nextStep = 1;
    curMax = 1+nums[begin+1];
    
    for(i = 1; i<=nums[begin]; ++i)
    {
        if(i+nums[begin+i]>=numsSize-1)
        {
            return 2;
        }
        if(i+nums[begin+i]>curMax)
        {
            curMax = i+nums[begin+i];
            nextStep = i;
        }
    }
    
    return 1+searchFast(nums, begin+nextStep, numsSize);
}

int jump(int* nums, int numsSize) {
    return searchFast(nums, 0, numsSize);
}