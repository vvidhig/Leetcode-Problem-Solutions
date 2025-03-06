class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++)
        {
            if(grid[i][0]==1)
            {
                visited[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1)
            {
                visited[i][m-1] = 1;
                q.push({i,m-1});
            }
        }
        for(int j = 0; j<m; j++)
        {
            if(grid[0][j]==1)
            {
                visited[0][j] = 1;
                q.push({0,j});
            }
            if(grid[n-1][j]==1)
            {
                visited[n-1][j] = 1;
                q.push({n-1,j});
            }
        }
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto [dx,dy] : directions)
            {
                int nrow = row+dx;
                int ncol = col+dy;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    count+=1;
                }
            }
        }
        return count;
    }
};
