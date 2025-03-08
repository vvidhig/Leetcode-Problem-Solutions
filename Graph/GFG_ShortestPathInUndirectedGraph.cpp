class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> res(n,-1);
        vector<int> visited(n, 0);
        visited[src] = 1;
        res[src] = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            for(auto adjNode : adj[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    res[adjNode] = cost + 1;
                    q.push({adjNode,cost+1});
                }
            }
        }
        return res;
    }
};
