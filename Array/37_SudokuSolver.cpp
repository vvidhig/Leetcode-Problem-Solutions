class Solution {
private:
    bool solve(vector<vector<char>>& board, unordered_set<char> rows[9], unordered_set<char> cols[9], unordered_set<char> boxes[9])
    {
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char ch = '1'; ch<='9'; ch++)
                    {
                        int boxIndex = (i/3)*3 + (j/3);
                        if(rows[i].count(ch) || cols[j].count(ch) || boxes[boxIndex].count(ch))
                        {
                            continue;
                        }
                        board[i][j] = ch;
                        rows[i].insert(ch);
                        cols[j].insert(ch);
                        boxes[boxIndex].insert(ch);
                        if(solve(board, rows, cols, boxes))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                        rows[i].erase(ch);
                        cols[j].erase(ch);
                        boxes[boxIndex].erase(ch);
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                char ch = board[i][j];
                if(ch == '.')
                {
                    continue;
                }
                rows[i].insert(ch);
                cols[j].insert(ch);
                int boxIndex = (i/3)*3 + (j/3);
                boxes[boxIndex].insert(ch);
            }
        }
        solve(board, rows, cols, boxes);
    }
};
