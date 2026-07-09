class DSU {
    public:
    vector<int>parent,size;
    DSU(int n ){
        parent.assign(n+1,0);
        size.assign(n+1,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    void join(int x,int y){
        x = find(x);
        y =find(y);
        if(x==y)return;
        if(size[y]>size[x])swap(x,y);
        parent[y]=x;
        size[x]+=size[y];
    }
};
class Solution {
public:

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU ds(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i+1]-nums[i])<=maxDiff)ds.join(i+1,i);
        }
        vector<bool>ans;
        for(auto q:queries){
            if(ds.find(q[0])==ds.find(q[1]))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

    }
};