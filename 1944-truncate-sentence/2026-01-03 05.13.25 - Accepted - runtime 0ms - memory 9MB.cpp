class Solution {
public:
    string truncateSentence(string s, int k) {
       int cnt=0;
       string ans="";
       for(char ch:s){
        if(ch==' ') cnt++;
        if(cnt==k) return ans;
        ans+=ch;
       }
       return s;
    }
};