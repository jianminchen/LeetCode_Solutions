int *
search(int *nums, int begin, int end, int target)
{
    int mid = 0;
    int *res = NULL,
        *firstHalf = NULL,
        *secondHalf = NULL;
    int first = -1,
        second = -1;
    
    res = (int *)malloc(2*sizeof(int));
    while(nums[begin] < nums[end] && (end - begin > 1))
    {
        mid = begin + (end - begin)/2;
        if(nums[mid] < target)
        {
            begin = mid;
        }
        else if(nums[mid] > target)
        {
            end = mid;
        }
        else
        {
            if(nums[begin] == target)
            {
                secondHalf = search(nums, mid, end, target);
                first = begin;
                second = secondHalf[1];
                free(secondHalf);
            }
            else if (nums[end] == target)
            {
                second = end;
                firstHalf = search(nums, begin, mid, target);
                first = firstHalf[0];
                free(firstHalf);
            }
            else
            {   
                firstHalf = search(nums, begin, mid, target);
                secondHalf = search(nums, mid, end, target);
                first = firstHalf[0];
                second = secondHalf[1];
                free(firstHalf);
                free(secondHalf);
            }
            break;
        }
    }
    
    if(nums[begin] == target && nums[end] == target)
    {
        first = begin;
        second = end;
    }
    else if(end - begin <=1)
    {
        if(nums[end] == target)
        {
            first = second = end;
        }
        if(nums[begin] == target)
        {
            first = second = begin;
        }
    }
    
    res[0] = first;
    res[1] = second;
    
    return res;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    
    return search(nums, 0, numsSize-1, target);
}