/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,
        curIdx,
        j;
    int *saveIdx;
    int *ret_idx;
    
    ret_idx = NULL;
    curIdx = 0;
    saveIdx = (int *)malloc(numsSize * sizeof(int));
    
    for(i = 0; i<numsSize; ++i)
    {
        for(j = 0; j< curIdx; ++j)
        {
            if(nums[i] + nums[saveIdx[j]] == target)
            {
                ret_idx = (int *)malloc(2*sizeof(int));
                ret_idx[0] = i;
                ret_idx[1] = saveIdx[j];
                break;
            }
        }
        saveIdx[curIdx] = i;
        curIdx ++;
    }
    
    free(saveIdx);
    return ret_idx;
}