class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto x:times)
        {
            adjList[x[0]].push_back({x[1], x[2]});
        }
        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        distance[k] = 0;
        while(!pq.empty())
        {
            int delay = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto adjNode : adjList[node])
            {
                if(delay + adjNode.second < distance[adjNode.first])
                {
                    distance[adjNode.first] = delay + adjNode.second;
                    pq.push({distance[adjNode.first], adjNode.first});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) return -1;
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};
