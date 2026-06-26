class Solution {
public:
   
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         unordered_map<string,int>id;
        int idx=0;
       for (auto &eq : equations) {
    if (!id.count(eq[0]))
        id[eq[0]] = idx++;

    if (!id.count(eq[1]))
        id[eq[1]] = idx++;
}
        vector<vector<double>>dist(idx,vector<double>(idx,-1));
        for(int i=0;i<equations.size();i++){
           int a =id[equations[i][0]];
           int b =id[equations[i][1]];
            double d = values[i];
            dist[a][b]=d;
            dist[a][a]=1.0;
            dist[b][b]=1.0;
            dist[b][a]=1.0/d;

        }
        for (int k = 0; k < idx; k++) {
    for (int i = 0; i < idx; i++) {
        if (dist[i][k] == -1) continue;

        for (int j = 0; j < idx; j++) {
            if (dist[k][j] == -1) continue;

            if (dist[i][j] == -1) {
                dist[i][j] = dist[i][k] * dist[k][j];
            }
        }
    }
}
        vector<double>ans;
        for(auto &q:queries){
            if(!id.count(q[0]) || !id.count(q[1])){
    ans.push_back(-1);
    continue;
}
            int a= id[q[0]];
            int b=id[q[1]];
            if(dist[a][b]!=-1){
                ans.push_back(dist[a][b]);
            }else ans.push_back(-1);
        }
        return ans;
    }
};