void 
rotateMatrix(int** matrix, int level, int matrixRowSize, int matrixColSize)
{
    int i = 0,
        save1 = 0,
        save2 = 0;
    
    if(matrixRowSize - 2*level <= 1)
    {
        return;
    }
    
    for(i=level; i<matrixRowSize-level-1; i++)
    {
        save1 = matrix[level][matrixColSize-1-i];
        matrix[level][matrixColSize-1-i] = matrix[i][level];
        save2 = matrix[matrixRowSize-1-i][matrixColSize-1-level];
        matrix[matrixRowSize-1-i][matrixColSize-1-level] = save1;
        save1 = matrix[matrixRowSize-1-level][i];
        matrix[matrixRowSize-1-level][i] = save2;
        matrix[i][level] = save1;
    }
    
    rotateMatrix(matrix, level+1, matrixRowSize, matrixColSize);
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    rotateMatrix(matrix, 0, matrixRowSize, matrixColSize);
}