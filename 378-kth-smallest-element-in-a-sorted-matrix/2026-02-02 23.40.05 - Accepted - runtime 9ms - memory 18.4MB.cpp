class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        for(int i =0;i<matrix.size();i++)pq.push({matrix[i][0],i,0});
        int ans =-1;
        while(!pq.empty()&& k--){
            auto[num,i,j]=pq.top();
            ans = num;
            pq.pop();
           if(j+1<matrix[0].size()) pq.push({matrix[i][j+1],i,j+1});
            
        }
        return ans;
    }
};