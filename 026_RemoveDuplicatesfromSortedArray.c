int removeDuplicates(int* nums, int numsSize) {
    int storeR0 = 0, /*Save value in register R0*/
        idx = 0,
        newLen = 1;
    
    if(numsSize <2)
    {
        return numsSize;
    }

    for(idx = 1; idx<numsSize; ++idx)
    {
        if(nums[idx] != nums[storeR0])
        {
            if(idx-storeR0>1)
            {
                nums[storeR0+1] = nums[idx];
            }
            storeR0 ++;
            newLen ++;
        }
    }
    
    return newLen;
}