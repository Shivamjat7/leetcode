class Solution {
    bool isInside(int x ,int y,int xc,int yc,int r){
        return (xc-x)*(xc-x)+ (yc-y)*(yc-y)<=r*r;
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &query:queries){
            int cnt =0;
            for(auto &point: points){
                if(isInside(point[0],point[1],query[0],query[1],query[2])) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};