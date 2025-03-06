class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({{i,j}, 0});
                }
            }
        }
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            distance[row][col] = step;
            q.pop();
            for(auto [dx, dy] : directions)
            {
                int newRow = row+dx;
                int newCol = col+dy;
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && visited[newRow][newCol]==0)
                {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, step+1});
                }
            }
        }
        return distance;
    }
};
