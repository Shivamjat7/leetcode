class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &edge:times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int> time(n+1,1e9);
        time[k]=0;
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            for(auto &[neigh,wt]:adj[node]){
                if(wt+t<time[neigh]){
                    time[neigh]=wt+t;
                    pq.push({wt+t,neigh});
                }
            }

        }
        int minTime =-1;
        for(int i =1;i<time.size();i++){
            if(time[i]==1e9) return -1;
            else if(time[i]>minTime) minTime =time[i];
        }
        return minTime;
    }
};