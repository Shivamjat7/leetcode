class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(char ch:tasks)mp[ch]++;
        int ans =0;
        priority_queue<pair<int ,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        
        for(auto [ch,freq]:mp)pq.push({0,ch});
        int timer=0;
        while(!pq.empty()){
           auto[t,ch]= pq.top();
           pq.pop();
           timer++;
           if(t>=timer){
            pq.push({t,ch});
            continue;
           }
           mp[ch]--;
           if(mp[ch]>0)pq.push({t+n+1,ch});
        }
        return timer;
    }
};