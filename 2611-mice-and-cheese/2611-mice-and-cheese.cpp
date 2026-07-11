class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int>pq;
        long long sum =0;
        for(int i =0;i<reward1.size();i++){
            pq.push(reward1[i]-reward2[i]);
            sum+=reward2[i];
            }

        while(!pq.empty()&& k>0){
            k--;
            sum+=pq.top();
            pq.pop();
            
        }
        return sum;
    }
};