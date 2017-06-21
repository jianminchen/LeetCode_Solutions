class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int level = 0,
            n = matrix.size();
        
        if(n<=1)
        {
            return;
        }
        
        while(level<n-1-level)
        {
            for(int i = level; i<n-1-level; ++i)
            {
                swap(matrix[i][level], matrix[n-1-level][i]);
                swap(matrix[n-1-level][i], matrix[n-1-i][n-1-level]);
                swap(matrix[n-1-i][n-1-level], matrix[level][n-1-i]);
            }
            ++level;
        }
    }
};