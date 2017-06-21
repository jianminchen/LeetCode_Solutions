double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double  res;
    int     idx1, idx2;
    int     *mergeNums;
    
    res = 0.0;
    idx1 = idx2 = 0;
    mergeNums = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    
    while(idx1 + idx2 < nums1Size+nums2Size)
    {
        if((nums1[idx1] >= nums2[idx2] && (idx2 < nums2Size)) || (idx1 == nums1Size))
        {
            mergeNums[idx1+idx2] = nums2[idx2];
            idx2 ++;
        }
        else
        {
            mergeNums[idx1+idx2] = nums1[idx1];
            idx1 ++;
        }
    }
    
    if((nums1Size+nums2Size)%2)
    {
        res = mergeNums[(nums1Size + nums2Size+1)/2 - 1];
    }
    else
    {
        res = 0.5 * (mergeNums[(nums1Size + nums2Size)/2 - 1] + mergeNums[(nums1Size + nums2Size)/2]);
    }
    
    free(mergeNums);
    return res;
}