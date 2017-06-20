void
swapInt(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    return;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0,
        ret = 0,
        end = 0;

    if(!numsSize)
    {
        return 1;
    }
    end = numsSize;
    while(i<end)
    {
        if(nums[i] == i+1)
        {
            i++;
        }
        else if(nums[i] <= 0 || nums[i] == nums[nums[i]-1] || nums[i]>end)
        {
            swapInt(nums, i, end-1);
            end --;
        }
        else
        {
            swapInt(nums, i, nums[i]-1);
        }
    }
    
    ret = end+1;
    return ret;
}