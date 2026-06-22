class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v, cost});
        }

        // Min-heap: {total_cost, node, stops}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!pq.empty()) {
            auto [stops, node, cost] = pq.top();
            pq.pop();

            // If destination reached, return cost
            if (stops > k) continue;

            for (auto &[next, price] : adj[node]) {
                int newCost = cost + price;
                // Allow reprocessing if within stop limit
                if (newCost < dist[next] && stops <= k) {
                    dist[next] = newCost;
                    pq.push({stops+1, next,newCost });
                }
            }
        }

        return dist[dst]==1e9?-1:dist[dst];
    }
};

