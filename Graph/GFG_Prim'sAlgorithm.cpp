class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,-1}});
        vector<int> visited(V, 0);
        int cost = 0;
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            if(!visited[node])
            {
                visited[node] = 1;
                cost += weight;
            }
            for(auto adjNode : adj[node])
            {
                int neighbour = adjNode[0];
                int neighbour_weight = adjNode[1];
                if(!visited[neighbour])
                {
                    pq.push({neighbour_weight, {neighbour, node}});
                }
                
            }
        }
        return cost;
    }
};
