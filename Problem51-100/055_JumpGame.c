bool canJump(int* nums, int numsSize) {
    if(numsSize == 1)
    {
        return true;
    }
    
    int isLast = nums[numsSize-1] == 0? 1:0,
        fromLastZero = 0;
        
    for(int idx = numsSize-1; idx>=0; --idx)
    {
        if(!nums[idx] && !fromLastZero)
        {
            fromLastZero = 1;
            continue;
        }
        
        if(!fromLastZero)
        {
            continue;
        }
        
        if(nums[idx]>(fromLastZero-isLast))
        {
            fromLastZero = 0;
            isLast = 0;
        }
        else
        {
            fromLastZero ++;
        }
    }
    
    return !fromLastZero;
}