/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int
compInterval(const void *a, const void *b)
{
    int num1 = ((struct Interval *)a)->start;
    int num2 = ((struct Interval *)b)->start;
    
    return num1>=num2?1:0;
}
 
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval *res;
    int             i, j, lastOne;
    int             *statArr;
    
    statArr = (int *)malloc(intervalsSize * sizeof(int));
    memset(statArr, 0, intervalsSize * sizeof(int));
    
    *returnSize = intervalsSize;
    res = NULL;
    qsort(intervals, intervalsSize, sizeof(struct Interval), compInterval);
    
    lastOne = 0;
    for(i = 1; i<intervalsSize; i++)
    {
        if(intervals[i].start <= intervals[lastOne].end)
        {
            intervals[lastOne].end = intervals[i].end>intervals[lastOne].end?intervals[i].end:intervals[lastOne].end;
            statArr[i] = 1;
            (*returnSize) --;
        }
        else
        {
            lastOne = i;
        }
    }
    
    res = (struct Interval *)malloc((*returnSize) * sizeof(struct Interval));
    
    for(i = 0, j = 0; i<*returnSize; ++i, ++j)
    {
        while(statArr[j] == 1)
        {
            ++j;
        }
        
        res[i].start = intervals[j].start;
        res[i].end = intervals[j].end;
    }
    
    free(statArr);
    return res;
}