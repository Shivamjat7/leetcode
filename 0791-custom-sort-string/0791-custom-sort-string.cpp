class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(auto ch:s)mp[ch]++;
        string ans="";
        for(char ch:order){
            while(mp[ch]>0){
                ans+=ch;
                mp[ch]--;
            }
        }
        for(auto [ch,freq]:mp){
            while(freq>0){
                ans+=ch;
                freq--;
            }
        }
        return ans;
    }
};