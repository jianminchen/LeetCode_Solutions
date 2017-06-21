int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int DP[gridRowSize][gridColSize];
    int i, j;
    
    DP[0][0] = grid[0][0];
    for(i = 1; i<gridRowSize; ++i)
    {
        DP[i][0] = grid[i][0]+DP[i-1][0];
    }
    
    for(j = 1; j<gridColSize; ++j)
    {
        DP[0][j] = grid[0][j]+DP[0][j-1];
    }
    
    for(i = 1; i<gridRowSize; ++i)
    {
        for(j = 1; j<gridColSize; ++j)
        {
            DP[i][j] = DP[i-1][j]<DP[i][j-1]?DP[i-1][j]:DP[i][j-1];
            DP[i][j] += grid[i][j];
        }
    }
    
    return DP[gridRowSize-1][gridColSize-1];
}