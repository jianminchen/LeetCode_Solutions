int maxArea(int* height, int heightSize) {
    int retMax, i, j, realH,water;
    
    i = realH = retMax = water = 0;
    j = heightSize-1;
    
    while(i < j)
    {
        realH = height[i]>height[j] ? height[j] : height[i];
        water = realH*(j-i);
        retMax = retMax>water?retMax:water;
        while(height[i]<=realH && i< j)
        {
            i++;
        }
        while(height[j]<=realH && i<j)
        {
            j--;
        }
    }
    return retMax;
}