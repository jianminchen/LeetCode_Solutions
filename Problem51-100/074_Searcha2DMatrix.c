bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
    int begin, mid, end, row, col;
    
    begin = 0;
    end = matrixRowSize-1;
    mid = begin + (end-begin)/2;
    
    if(!matrixRowSize || !matrixColSize)
    {
        return false;
    }
    
    while(begin!=mid && mid != end)
    {
        if(matrix[mid][0]==target)
        {
            return true;
        }
        else if(matrix[mid][0]>target)
        {
            end = mid;
        }
        else
        {
        
            begin = mid;
        }
        
        mid = begin + (end-begin)/2;
    }

    if(matrix[begin][0] == target  || matrix[end][0] == target)
    {
        return true;
    }
    else if(matrix[end][0]<target)
    {
        row = end;
    }
    else
    {
        row = begin;
    }
    
    begin = 0;
    end = matrixColSize -1;
    mid = begin + (end-begin)/2;

    while(begin!= mid && mid != end)
    {
        if(matrix[row][mid] == target)
        {
            return true;
        }
        else if(matrix[row][mid]>target)
        {
            end = mid;
        }
        else
        {
            begin = mid;
        }
        mid = begin + (end-begin)/2;
    }
    
    if(matrix[row][begin] == target ||
        matrix[row][end] == target)
    {
        return true;
    }
    else
    {
        return false;
    }
}