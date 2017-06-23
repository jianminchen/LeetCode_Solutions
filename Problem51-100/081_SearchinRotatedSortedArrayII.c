bool search(int* nums, int numsSize, int target) {
    int begin, end, mid;
    
    begin = 0;
    end = numsSize-1;
    mid = begin + (end-begin)/2;
    
    while(begin<end) 
    {
        mid = (begin+end)/2;
        if(nums[mid] == target)
        {
            return true;
        }
        if(nums[mid]>nums[end])
        {
            if(target>=nums[begin] && target<nums[mid])
            {
                end = mid;
            }
            else
            {
                begin = mid+1;
            }
        }
        else if(nums[mid] < nums[end])
        {
            if(target>nums[mid] && target<=nums[end])
            {
                begin = mid+1;
            }
            else
            {
                end = mid;
            }
        }
        else
        {
            --end;
        }
    }
    
    return nums[begin] == target?true:false;
}