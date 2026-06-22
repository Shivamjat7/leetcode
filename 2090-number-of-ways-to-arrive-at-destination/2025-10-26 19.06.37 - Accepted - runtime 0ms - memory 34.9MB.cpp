class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        vector<long long> dist(n, INF);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue; // skip outdated entry

            for (auto &[neigh, wt] : adj[node]) {
                long long newDist = d + wt;
                if (newDist < dist[neigh]) {
                    dist[neigh] = newDist;
                    ways[neigh] = ways[node];
                    pq.push({newDist, neigh});
                } else if (newDist == dist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
