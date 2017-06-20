int
searchMax(int *height, int begin, int end)
{
    int curMax = height[begin],
        i = 0,
        idx = begin;
    
    for(i = begin+1; i < end; i++)
    {
        idx = curMax>height[i]?idx:i;
        curMax = height[idx];
    }
    
    return idx;
}

int trap(int* height, int heightSize) {
    int blackArea = 0,
        totalArea = 0,
        i = 0,
        curMax = height[0], 
        idx = 0, 
        firstIdx = 0,
        secondIdx = 0,
        firstEnd = 0;
        
    for(i = 0; i<heightSize; i++)
    {
        blackArea += height[i];
        idx = height[i]>curMax?i:idx;
        curMax = height[idx];
    }
    
    firstIdx = firstEnd = idx;

    while(firstIdx)
    {
        firstIdx = searchMax(height, 0, firstEnd);
        totalArea += height[firstIdx]*(firstEnd-firstIdx);
        firstEnd = firstIdx;
    }
    
    while(idx<heightSize)
    {
        secondIdx = idx+1;
        totalArea += height[idx];
        idx = searchMax(height, secondIdx, heightSize);
        totalArea += height[idx]*(idx - secondIdx);
        secondIdx = idx+1;
    }

    return totalArea-blackArea;
}