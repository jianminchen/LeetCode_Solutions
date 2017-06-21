int search(int* nums, int numsSize, int target) {
    int begin = 0,
        end = numsSize - 1,
        mid = (end - begin)/2,
        res = 0;
    
    while(begin < end-1)
    {
        if(nums[begin] >= nums[mid])
        {
            if(target >= nums[mid] && target<=nums[end])
            {
                begin = mid;
            }
            else
            {
                end = mid;
            }
        }
        else
        {
            if(target <= nums[mid] && target >= nums[begin])
            {
                end = mid;
            }
            else
            {
                begin = mid;
            }
        }
        mid = begin + (end - begin)/2;
    }
    
    res = (target == nums[begin])?begin:-1;
    if(begin < end && res == -1)
    {
        res = (target == nums[end])?end:-1;
    }
    
    return res;
}