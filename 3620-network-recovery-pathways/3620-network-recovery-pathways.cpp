class Solution {
public:
    bool pathExist(int x,long long k , vector<bool>&online,vector<vector<pair<int,int>>>&adj){
        int n =adj.size();
        vector<long long>dist(n,LLONG_MAX);
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();
            if(d>k || d>dist[node])continue;

            for(auto[neigh,wt]:adj[node]){
                if(wt < x) continue;
                if( !online[neigh]) continue;
                    if(dist[node]+wt<dist[neigh]){
                        dist[neigh]=d+wt;
                        pq.push({d+wt,neigh});
                    }
                
            }

        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n =online.size();
        vector<vector<pair<int,int>>>adj(n);
        int mxEdgeWt=-1;
        for(auto &e:edges){
            mxEdgeWt = max(mxEdgeWt,e[2]);
            adj[e[0]].push_back({e[1],e[2]});
        }
        int ans=-1;
        int low =0,high=mxEdgeWt;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(pathExist(mid,k,online,adj)){
                ans = mid;
                low = mid+1;
            }else high=mid-1;
        }
        
    

        return ans;
    }
};