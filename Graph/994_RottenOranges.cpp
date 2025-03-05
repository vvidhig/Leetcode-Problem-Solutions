class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j]==1)
                {
                    fresh+=1;
                }
            }
        }

        if (fresh == 0) return 0;

        int time = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        while(!q.empty())
        {
            int size = q.size();
            bool new_rotten = false;

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        fresh--;
                        new_rotten = true;
                    }
                }
            }

            if (new_rotten) time++;
        }
        return fresh == 0 ? time : -1;
    }
};
