class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1]==1)
        {
            return -1;
        }
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 0});
        vector<vector<int>> visited(n, vector<int>(m,0));
        visited[0][0]=1;
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            if(row==n-1 && col==m-1)
            {
                return step+1;
            }
            for(auto [dx,dy] : directions)
            {
                int nrow = row+dx;
                int ncol = col+dy;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==0)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step+1});
                }
            }
        }
        return -1;
    }
};
