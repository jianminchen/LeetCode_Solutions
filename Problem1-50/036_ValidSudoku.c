#define CK_ROW  0
#define CK_COL  1
#define CK_CELL 2

bool
check_valid(char **board, int row, int col, int mod)
{
    int ckArr[9] = {0};
    int i = 0,
        j = 0,
        num = 0;
    
    if(mod == CK_ROW)
    {
        for(i = 0; i<9; i++)
        {
            if(board[row][i] == '.')
            {
                continue;
            }
            
            num = board[row][i] - '1' + 0;
            if(ckArr[num])
            {
                return false;
            }
            else
            {
                ckArr[num] = 1;
            }
        }
        
        return true;
    }
    else if(mod == CK_COL)
    {
        for(i = 0; i<9; i++)
        {
            if(board[i][col] == '.')
            {
                continue;
            }
            
            num = board[i][col] - '1' + 0;
            if(ckArr[num])
            {
                return false;
            }
            else
            {
                ckArr[num] = 1;
            }
        }
        
        return true;
    }
    else
    {
        for(i = 0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(board[row+i][col+j] == '.')
                {
                    continue;
                }
                num = board[row+i][col+j] - '1' + 0;
                if(ckArr[num])
                {
                    return false;
                }
                else
                {
                    ckArr[num] = 1;
                }
            }
        }
        
        return true;
    }
}

bool 
isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int r = 0,
        c = 0;
    
    for(r = 0; r<boardRowSize; ++r)
    {
        if(!check_valid(board, r, 0, CK_ROW))
        {
            return false;
        }
    }
    
    for(c = 0; c < boardColSize; ++c)
    {
        if(!check_valid(board, 0, c, CK_COL))
        {
            return false;
        }
    }
    
    for(r = 0; r < boardRowSize; r += 3)
    {
        for(c = 0; c < boardColSize; c += 3)
        {
            if(!check_valid(board, r, c, CK_CELL))
            {
                return false;
            }
        }
    }
    
    return true;
}