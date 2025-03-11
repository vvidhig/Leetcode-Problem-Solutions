class Solution {
  private:
    int findParent(int x, vector<int>& parent)
    {
        if(parent[x] == x)
        {
            return x;
        }
        int p = findParent(parent[x], parent);
        return p;
    }
    void unionByRank(vector<int>& rank, vector<int>& parent, int u, int v)
    {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]+=1;
        }
    }
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) 
    {
        // code here
        int cost = 0;
        int edges = 0;
        vector<int> rank(V, 0);
        vector<int> parent(V);
        for(int i = 0; i<V; i++)
        {
            parent[i]=i;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,-1}});
        for(int i = 0; i<V; i++)
        {
            for(int j = 0; j<adj[i].size(); j++)
            {
                pq.push({adj[i][j][1], {i, adj[i][j][0]}});
            }
        }
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int parentNode = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if(findParent(node, parent) != findParent(parentNode, parent))
            {
                cost += weight;
                unionByRank(rank, parent, node, parentNode);
                edges+=1;
            }
            if(edges == V-1)
            {
                break;
            }
        }
        return cost;
    }
};
