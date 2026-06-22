class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=0;
        for(char ch:s){
            x=x^(ch-'a');
        }
        for(char ch:t){
            x=x^(ch-'a');
        }
        return char(x+'a');
    }
};