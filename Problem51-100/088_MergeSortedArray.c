void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, k;
    j = m-1;
    k = n-1;
    
    for(i=m+n-1; i>=0;--i)
    {
        if(j>=0 && k>=0 && nums1[j]>nums2[k])
        {
            nums1[i] = nums1[j];
            --j;
        }
        else if(k<0)
        {
            break;
        }
        else
        {
            nums1[i] = nums2[k];
            --k;
        }
    }
}