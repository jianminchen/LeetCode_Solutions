int searchInsert(int* nums, int numsSize, int target) {
    int i = 0,
        res = 0;

    if(numsSize == 0 || 
        (numsSize == 1 && nums[0] >= target))
    {
        return 0;
    }
    else if(numsSize == 1)
    {
        return 1;
    }
    
    if(target<=nums[0])
    {
        return 0;
    }
    
    for(i = 0; i<numsSize; ++i)
    {
        if(nums[i] == target)
        {
            return i;
        }
        else if(nums[i]<target)
        {
            res = i;
        }
        else
        {
            return res+1;
        }
    }
    
    return res+1;
}