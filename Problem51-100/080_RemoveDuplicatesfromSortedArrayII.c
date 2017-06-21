int removeDuplicates(int* nums, int numsSize) {
    int storeR0, 
        newLen,
        idx;
    
    newLen = 0;
    storeR0 = INT_MAX;
    
    for(idx = 0; idx<numsSize; ++idx)
    {
        if(nums[idx] != storeR0)
        {
            nums[newLen] = nums[idx];
            storeR0 = nums[idx];
            newLen++;
        }
        else 
        {
            while(idx+1<numsSize && nums[idx+1]==storeR0)
            {
                ++idx;
            }

            nums[newLen] = storeR0;
            newLen++;
        }
    }
    
    return newLen;
}