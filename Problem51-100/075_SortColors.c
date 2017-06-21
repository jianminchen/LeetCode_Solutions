void sortColors(int* nums, int numsSize) {
    int i, j;
    
    i = 0;
    j = numsSize -1;
    while(i<=j)
    {
        if(nums[i] == 0)
        {
            ++i;
            continue;
        }
        if(nums[j] !=0)
        {
            --j;
            continue;
        }
        nums[j] = nums[i];
        nums[i] = 0;
        --j;
        ++i;
    }

    j = numsSize -1;
    while(i<=j)
    {
        if(nums[i] == 1)
        {
            ++i;
            continue;
        }
        if(nums[j] == 2)
        {
            --j;
            continue;
        }
        nums[j] = 2;
        nums[i] = 1;
        --j;
        ++i;
    }
}