class Solution {
private:
    void dfsTraversal(int node, vector<vector<int>>& isConnected, vector<int>& visited)
    {
        visited[node] = 1;
        for(int k = 0; k<isConnected.size(); k++)
        {
            if(isConnected[node][k] && !visited[k])
            {
                dfsTraversal(k, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int count = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                count += 1;
                dfsTraversal(i, isConnected, visited);
            }
        }
        return count;
    }
};
