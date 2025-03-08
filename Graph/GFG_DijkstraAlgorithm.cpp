class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) 
    {
        // Code here
        int n = adj.size();
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[src] = 0;
        pq.push({src, 0});
        while(!pq.empty())
        {
            int node = pq.top().first;
            int curr_dist = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int next_dist = it.second;
                int next_node = it.first;
                if(next_dist+curr_dist < distance[next_node])
                {
                    distance[next_node] = next_dist+curr_dist;
                    pq.push({next_node, distance[next_node]});
                }
            }
        }
        return distance;
    }
};
