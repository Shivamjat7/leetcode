class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n =status.size();
        vector<int>vis(n,0);
        vector<int>boxes(n,0);
        queue<int>q;
        int candy=0;
        for(int box:initialBoxes){
            if(status[box]){
                q.push(box);
            }
             boxes[box]=1;
        }
        while(!q.empty()){
           int box= q.front();
           q.pop();
           if(vis[box])continue;
           candy+=candies[box];
           vis[box]=1;
           for(int b:containedBoxes[box]){
            boxes[b]=1;
            if(!vis[b]&&status[b]){
                q.push(b);
            }
           }
           for(int k:keys[box]){
            status[k]=1;
           if(boxes[k] && !vis[k] ) {
            q.push(k);
           }
           }
        }
        return candy;
    }
};