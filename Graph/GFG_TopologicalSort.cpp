class Solution {
  private:
    void dfs(int node, vector<vector<int>>&adj, vector<int>& visited, stack<int>& st)
    {
        visited[node] = 1;
        for(auto adjnode : adj[node])
        {
            if(!visited[adjnode])
            {
                dfs(adjnode, adj, visited, st);
            }
        }
        st.push(node);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> ans;
        int n = adj.size();
        vector<int> visited(n, 0);
        stack<int> st;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
