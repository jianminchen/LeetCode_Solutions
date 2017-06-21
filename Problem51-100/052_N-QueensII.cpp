class Solution {
public:
    int totalNQueens(int n) {
        vector<string>          cur(n, string(n,'.'));
        int res=0;
        
        genSolution(&res, cur, 0, n);

        return res;
    }
    
    void genSolution(int *res, vector<string>& cur, int row, int n)
    {
        if(row==n)
        {
            (*res) ++;
            return;
        }

        for(int i =0; i<n; ++i)
        {
            if(isValid(cur, row, i, n))
            {
                cur[row][i] = 'Q';
                genSolution(res, cur, row+1, n);
                cur[row][i] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& cur, int row, int col, int n)
    {
        int j, i;
        for(i = 0; i<row; ++i)
        {
            if(cur[i][col] == 'Q')
            {
                return false;
            }
        }
        
        for(i = row-1, j = col-1; i>=0 && j>=0 ; --i, --j)
        {
            if(cur[i][j] == 'Q')
            {
                return false;
            }
        }
        
        for(i = row-1, j = col+1; i>=0 && j<n; --i, ++j)
        {
            if(cur[i][j] == 'Q')
            {
                return false;
            }
        }
        
        return true;
    }
};