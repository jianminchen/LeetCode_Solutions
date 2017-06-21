bool ckStr(char **board, int row, int col, int rowSize, int colSize, char *word)
{
    char save;
    
    if(!*word)
    {
        return true;
    }
    
    if(board[row][col] != *word)
    {
        return false;
    }
    else if(rowSize == 1 && colSize == 1  && !*(word+1))
    {
        return true;
    }
    
    save = board[row][col];
    board[row][col] = '*';
    
    if(row>0 && ckStr(board, row-1, col, rowSize, colSize, word+1))
    {
        board[row][col] = save;
        return true;        
    }
    
    if(col>0 && ckStr(board, row, col-1, rowSize, colSize, word+1))
    {
        board[row][col] = save;
        return true;         
    }
    
    if(row<rowSize-1 && ckStr(board, row+1, col, rowSize, colSize, word+1))
    {
        board[row][col] = save;
        return true;
    }
    
    if(col<colSize-1 && ckStr(board, row, col+1, rowSize, colSize, word+1))
    {
        board[row][col] = save;
        return true;
    }
    
    board[row][col] = save;
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int     i,j;
    
    for(i = 0;i<boardRowSize;++i)
    {
        for(j = 0;j<boardColSize; ++j)
        {
            if(ckStr(board, i, j, boardRowSize, boardColSize, word))
            {
                return true;
            }
        }
    }
    
    return false;
}