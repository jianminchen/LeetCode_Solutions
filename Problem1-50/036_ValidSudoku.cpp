class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>   rowC(9, set<char>()),
                            colC(9, set<char>());
        vector<vector<set<char>>>   boxC(3, vector<set<char>>(3, set<char>()));
        
        if(board.size() == 0) {
            return false;
        }
        for(int i = 0; i<board.size(); ++i) {
            for(int j = 0; j<board[0].size(); ++j) {
                char c = board[i][j];
                if(c == '.') {
                    continue;
                }
                if(rowC[i].count(c) || colC[j].count(c) || boxC[i/3][j/3].count(c)) {
                    return false;
                }
                
                rowC[i].insert(c);
                colC[j].insert(c);
                boxC[i/3][j/3].insert(c);
            }
        }
        return true;
    }
};