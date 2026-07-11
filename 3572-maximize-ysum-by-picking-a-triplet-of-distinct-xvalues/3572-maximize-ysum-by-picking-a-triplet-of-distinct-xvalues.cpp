class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,int>>pq;
        int n = y.size();
        for(int i=0;i<n;i++)pq.push({y[i],i});
        unordered_set<int>st;
        int sum=0;
        while(!pq.empty()){
            auto [val,index]  = pq.top();
            pq.pop();
            if(st.contains(x[index]))continue;
            st.insert(x[index]);
            sum+=val;
            if(st.size()==3)return sum;
        }
        return -1;
    }
};