class Solution {
private:
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto x:roads)
        {
            adjList[x[0]].push_back({x[1], x[2]});
            adjList[x[1]].push_back({x[0], x[2]});
        }
        vector<long long> distance(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        while(!pq.empty())
        {
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            for(auto adjNode : adjList[node])
            {
                if(dist + adjNode.second < distance[adjNode.first])
                {
                    distance[adjNode.first] = dist + adjNode.second;
                    pq.push({distance[adjNode.first], adjNode.first});
                    ways[adjNode.first] = ways[node];
                }
                else if(dist + adjNode.second == distance[adjNode.first])
                {
                    ways[adjNode.first] = (ways[node] + ways[adjNode.first]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
