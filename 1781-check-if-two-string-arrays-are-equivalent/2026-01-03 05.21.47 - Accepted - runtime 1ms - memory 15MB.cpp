class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="";
        for(auto x:word1)s+=x;
        int i=0;
        for(auto str:word2){
            for(char ch: str){
                if(i>=s.size())return false;
                if(ch!=s[i]) return false;
                i++;
            }
        }
        if(i<s.size())return false;
        return true;
    }
};