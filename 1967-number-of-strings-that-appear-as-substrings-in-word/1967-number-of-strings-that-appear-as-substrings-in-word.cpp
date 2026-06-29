class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt =0;
        for(auto str:patterns){
            if(str.size()>word.size())continue;
            if(word.find(str)!=string::npos)cnt++;
        }
        return cnt;
        
    }
};