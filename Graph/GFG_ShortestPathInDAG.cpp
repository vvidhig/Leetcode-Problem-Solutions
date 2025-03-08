class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> pathCost(V, INT_MAX);
        queue<int> q;
        q.push(0);
        pathCost[0] = 0;
        vector<vector<pair<int, int>>> adjList(V);
        for(auto edge: edges)
        {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto adjPair : adjList[node]) {  
                int adjNode = adjPair.first;
                int weight = adjPair.second;

                if (pathCost[node] + weight < pathCost[adjNode]) {
                    pathCost[adjNode] = pathCost[node] + weight;
                    q.push(adjNode);
                }
            }
        }
        for(auto &x:pathCost)
        {
            if(x==INT_MAX)
            {
                x = -1;
            }
        }
        return pathCost;
    }
};
