class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        for(auto num:arr){
            pq.push({abs(num-x),num});
        }
        while(!pq.empty() && k--){
            int num = pq.top().second; 
            pq.pop();
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};