class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<long long,int>mp;
        for(auto &row:wall){
            long long prefix =0;
            for(int i =0;i<row.size()-1;i++){
             prefix =prefix+row[i];
             mp[prefix]++;
            }
        }
        int mx=0;
        for(auto &[pos,cnt]:mp){
            mx=max(mx,cnt);
        }
        return wall.size()-mx;
    }
};