class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int, int>>> adjList(n);
        int edges = flights.size();
        for(auto &x:flights)
        {
            adjList[x[0]].push_back({x[1], x[2]});
        }
        queue<pair<pair<int, int>, int>> q;
        vector<int> distance(n, INT_MAX);
        q.push({{src,0}, 0});
        distance[src] = 0;
        while(!q.empty())
        {
            int node = q.front().first.first;
            int cost = q.front().first.second;
            int stop = q.front().second;
            q.pop();
            if (stop > k) 
                continue;
            for(auto x:adjList[node])
            {
                if(cost + x.second < distance[x.first])
                {
                    distance[x.first] = cost + x.second;
                    q.push({{x.first,distance[x.first]}, stop+1});
                }
            }
        } 
        return distance[dst] == INT_MAX ? -1 : distance[dst];       
    }
};
