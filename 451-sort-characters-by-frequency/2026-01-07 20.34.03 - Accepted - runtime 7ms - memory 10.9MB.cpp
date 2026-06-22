class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for( char ch: s) mpp[ch]++;
        string str="";
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto[freq,ch]=pq.top();
            pq.pop();
            while(freq--){
                str+=ch;
            }
        }
      
        return str;
        
    }
};