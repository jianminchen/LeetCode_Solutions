/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int rowD[4] = {0,1,0,-1};
    int colD[4] = {1,0,-1,0};
    int row, rowE, col, colE, turnCount, idx, rowS, colS, tmp;
    int **res = malloc(n*sizeof(int *));
    
    if(n==0)
    {
        return NULL;
    }
    
    for(idx = 0; idx<n;++idx)
    {
        res[idx] = malloc(n*sizeof(int));
    }
    row = col = turnCount = rowS = colS = 0;
    idx = 1;
    rowE = n-1;
    colE = n-1;
    
    while(true)
    {
        res[row][col] = idx;
        ++idx;
        
        if(rowD[turnCount%4] 
            && rowD[turnCount%4]*(row+rowD[turnCount%4])> rowD[turnCount%4]*rowE)
        {
            if(col == colE)
            {
                break;
            }
            turnCount++;
            tmp = rowS;
            rowS = rowE;
            rowE = tmp;
            colS += colD[turnCount%4];
        }
        if(colD[turnCount%4]
            && colD[turnCount%4]*(col+colD[turnCount%4])> colD[turnCount%4]*colE)
        {
            if(row == rowE)
            {
                break;
            }
            turnCount++;
            tmp = colS;
            colS = colE;
            colE = tmp;
            rowS += rowD[turnCount%4];
        }

        row += rowD[turnCount%4];
        col += colD[turnCount%4];
    }
    
    return res;
}