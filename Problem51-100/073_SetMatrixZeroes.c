#define CVT_TO_ZERO  0x00000001

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int state[matrixRowSize][matrixColSize];
    int i, j, k;
    
    memset(state, 0, matrixRowSize*matrixColSize*sizeof(int));
    
    for(i = 0; i<matrixRowSize; ++i)
    {
        for(j = 0; j<matrixColSize; ++j)
        {
            if(matrix[i][j] == 0 && !(state[i][j] & CVT_TO_ZERO))
            {
                for(k = 0; k<matrixColSize; ++k)
                {
                    if(matrix[i][k] == 0)
                    {
                        continue;
                    }
                    matrix[i][k] = 0;
                    state[i][k] |= CVT_TO_ZERO;
                }
                for(k=0;k<matrixRowSize;++k)
                {
                    if(matrix[k][j] == 0)
                    {
                        continue;
                    }
                    matrix[k][j] = 0;
                    state[k][j] |= CVT_TO_ZERO;
                }
            }
        }
    }
}