class Solution {
public:
    void dfs(int room,vector<vector<int>>& rooms,vector<bool>&vis){
        for(int key:rooms[room]){
            if(!vis[key]){
                vis[key]=true;
                dfs(key,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        dfs(0,rooms,vis);
        for(auto x: vis) if(!x)return false;
        return true;
    }
};