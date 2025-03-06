class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int c = image[sr][sc];
        image[sr][sc] = color;
        if (c == color) return image;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i<size; i++)
            {
                auto [row, col] = q.front();
                q.pop();
                for(auto [dx,dy]:directions)
                {
                    int newRow = row+dx;
                    int newCol = col+dy;
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol] == c)
                    {
                        q.push({newRow, newCol});
                        image[newRow][newCol] = color;
                    }
                }
            }
        }
        return image;
    }
};
