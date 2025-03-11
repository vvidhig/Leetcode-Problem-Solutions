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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int cost = 0;
        vector<int> rank(n, 0);
        vector<int> parent(n);
        for(int i = 0; i<n; i++)
        {
            parent[i]=i;
        }
        for(int i = 0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            int pu = findParent(u, parent);
            int pv = findParent(v, parent);
            if(pu == pv)
            {
                cost += 1;
            }
            else
            {
                unionByRank(rank, parent, pu, pv);
            }
        }
        int component = 0;
        for(int i = 0; i<n; i++)
        {
            if(parent[i]==i)
            {
                component += 1;
            }
        }
        if(cost >= (component-1))
        {
            return component-1;
        }
        return -1;
    }
};
