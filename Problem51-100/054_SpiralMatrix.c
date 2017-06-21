/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int rowD[4] = {0,1,0,-1};
    int colD[4] = {1,0,-1,0};
    int row, rowE, col, colE, turnCount, idx, rowS, colS, tmp;
    int *res;
    
    res = (int *)malloc(matrixRowSize*matrixColSize*sizeof(int));
    row = col = turnCount = idx = rowS = colS = 0;
    rowE = matrixRowSize-1;
    colE = matrixColSize-1;
    
    while(true)
    {
        res[idx] = matrix[row][col];
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