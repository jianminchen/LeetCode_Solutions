int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int DP[100][100] = {0};
    int i, j;
    
    for(i = 0; i<obstacleGridRowSize && !obstacleGrid[i][0]; ++i)
    {
        DP[i][0] = 1;
    }
    for(j = 0; j<obstacleGridColSize && !obstacleGrid[0][j]; ++j)
    {
        DP[0][j] = 1;
    }
    
    for(i=1;i<obstacleGridRowSize; ++i)
    {
        for(j=1;j<obstacleGridColSize;++j)
        {
            if(obstacleGrid[i][j] == 0)
            {
                DP[i][j] = DP[i-1][j]+DP[i][j-1];
            }
            else
            {
                DP[i][j] = 0;
            }
        }
    }
    return DP[obstacleGridRowSize-1][obstacleGridColSize-1];
}