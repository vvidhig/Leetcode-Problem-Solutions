class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> distance(n, vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();
            if(row==n-1 && col==m-1)
            {
                return dist;
            }
            for(auto [dx,dy] : directions)
            {
                int nrow = row+dx;
                int ncol = col+dy;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int new_dist = max(abs(heights[nrow][ncol] - heights[row][col]), dist);
                    if(new_dist < distance[nrow][ncol])
                    {
                        distance[nrow][ncol] = new_dist;
                        pq.push({new_dist,{nrow, ncol}});
                    }
                }
            }
        }
        return 0;

    }
};
