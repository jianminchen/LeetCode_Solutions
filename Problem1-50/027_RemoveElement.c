bool compInt(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b?true:false);
}

int removeElement(int* nums, int numsSize, int val) {
    int i, offset;
    qsort(nums, numsSize, sizeof(int), compInt);
    offset = i = 0;
    
    while(i<numsSize)
    {
        if(nums[i] == val)
        {
            break;
        }
        ++i;
    }
    
    if(i == numsSize)
    {
        return numsSize;
    }
    
    while(i<numsSize && nums[i] == val)
    {
        offset ++;
        ++i;
    }
    
    while(i<numsSize)
    {
        nums[i-offset] = nums[i];
        ++i;
    }

    return numsSize-offset;
}