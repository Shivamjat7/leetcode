class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int,int>>vis;
    
        int cost=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{points[0][0],points[0][1]}});
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int wt = it.first;
            auto [x,y] =it.second;
            if(vis.count({x,y}))continue;
            vis.insert({x,y});
            cost+=wt;
            for(auto &point:points){
                if(!vis.count({point[0],point[1]})){
                    int dist = abs(point[0]-x) + abs(point[1]-y);
                    pq.push({dist,{point[0],point[1]}});
                }
            }

        }
        return cost;

    }
};