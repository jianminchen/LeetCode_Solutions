/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *res;
    int i;
    
    i = digitsSize-1;
    res = (int *)malloc((digitsSize+1) * sizeof(int));
    while(i>0 && digits[i]+1>9)
    {
        res[i] = 0;
        --i;
    }
    if(i>0)
    {
        res[i] = digits[i]+1;
        --i;
        while(i>=0)
        {
            res[i] = digits[i];
            --i;
        }
        *returnSize = digitsSize;
    }
    else
    {
        if(digits[0]+1>9)
        {
            res[0] = 1;
            res[digitsSize] = 0;
            *returnSize = digitsSize+1;
        }
        else
        {
            res[0] = digits[0]+1;
            *returnSize = digitsSize;
        }
    }
    
    return res;
}