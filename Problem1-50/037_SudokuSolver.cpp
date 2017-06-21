class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
        {
            return;
        }
        
        int n = board.size();
        set<pair<int, int>>         eSet;
        vector<vector<set<char>>>   boxC(3, vector<set<char>>(3, set<char>()));
        vector<set<char>>           rowC(9, set<char>()),
                                    colC(9, set<char>());
                                    
        map<pair<int, int>, set<char>>  eaMap;
        
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                char c = board[i][j];
                if(c != '.')
                {
                    rowC[i].insert(c);
                    colC[j].insert(c);
                    boxC[i/3][j/3].insert(c);
                }
                else
                {
                    eSet.insert(make_pair(i,j));
                }
            }
        }
        
        for(auto e : eSet)
        {
            int row = e.first,
                col = e.second;
                
            for(char c = '1'; c<='9'; ++c)
            {
                if(!rowC[row].count(c) 
                    && !colC[col].count(c) 
                    && !boxC[row/3][col/3].count(c))
                {
                    eaMap[e].insert(c);
                }
            }
        }
        
        pair<int, int>  pos;
        while(hasOnlyOne(eaMap, pos))
        {
            char c = *eaMap[pos].begin();
            
            board[pos.first][pos.second] = c;
            rowC[pos.first].insert(c);
            colC[pos.second].insert(c);
            boxC[pos.first/3][pos.second/3].insert(c);
            
            eaMap.erase(pos);
            eSet.erase(pos);
            
            for(auto e : eSet)
            {
                if(e.first == pos.first
                    || e.second == pos.second
                    || (e.first/3 == pos.first/3 && e.second/3 == pos.second/3))
                {
                    eaMap[e].erase(c);
                }
            }
        }
        
        vector<pair<int, int>>  eVec(eSet.begin(), eSet.end());
        
        dfs(0, eVec, eaMap, board);
    }
    
    bool hasOnlyOne(map<pair<int, int>, set<char>> &eaMap, pair<int, int>& pos)
    {
        for(auto e : eaMap)
        {
            if(e.second.size() == 1)
            {
                pos = e.first;
                return true;
            }
        }
        
        return false;
    }
    
    bool dfs(int idx, vector<pair<int, int>>& eVec, map<pair<int, int>, set<char>>&  eaMap, vector<vector<char>>& board)
    {
        if(idx == eVec.size())
        {
            return true;
        }
        
        pair<int, int> pos = eVec[idx];
        
        for(auto c : eaMap[pos])
        {
            board[pos.first][pos.second] = c;
            set<pair<int, int>> rm;
            
            for(int i = idx+1; i<(int)eVec.size(); ++i)
            {
                if((eVec[i].first == pos.first 
                    || eVec[i].second == pos.second
                    || (eVec[i].first/3 == pos.first/3 && eVec[i].second/3 == pos.second/3))
                    && eaMap[eVec[i]].count(c))
                {
                    rm.insert(eVec[i]);
                    eaMap[eVec[i]].erase(c);
                }
            }
            
            if(dfs(idx+1, eVec, eaMap, board))
            {
                return true;
            }
            else
            {
                board[pos.first][pos.second] = '.';
                for(auto p : rm)
                {
                    eaMap[p].insert(c);
                }
            }
        }
        
        return false;
    }
};