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
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval *res;
    int i, mergeEnd, mergeStart;
    
    *returnSize = 0;
    
    if(!intervalsSize)
    {
        *returnSize = 1;
        res = (struct Interval *)malloc(sizeof(struct Interval));
        res[0].start = newInterval.start;
        res[0].end = newInterval.end;
        return res;
    }
    
    res = (struct Interval *)malloc((intervalsSize+1) * sizeof(struct Interval));
    mergeEnd = newInterval.end;
    mergeStart = newInterval.start;

    i= 0;
    while(intervals[i].end<newInterval.start && i<intervalsSize)
    {
        res[*returnSize].start = intervals[i].start;
        res[*returnSize].end = intervals[i].end;
        ++i;
        ++(*returnSize);
    }

    if(i!=intervalsSize)
    {
        mergeStart = newInterval.start<=intervals[i].start?newInterval.start:intervals[i].start;
    }
    
    while(intervals[i].start<=newInterval.end && i<intervalsSize)
    {
        mergeEnd = newInterval.end>=intervals[i].end?newInterval.end:intervals[i].end;
        ++i;
    }
    
    res[*returnSize].start = mergeStart;
    res[*returnSize].end = mergeEnd;
    ++(*returnSize);

    while(i<intervalsSize)
    {
        res[*returnSize].start = intervals[i].start;
        res[*returnSize].end = intervals[i].end;
        ++i;
        ++(*returnSize);
    }
    
    return res;
}