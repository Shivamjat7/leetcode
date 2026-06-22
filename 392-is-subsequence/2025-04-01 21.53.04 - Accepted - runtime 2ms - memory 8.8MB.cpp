class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        queue<char> q;
        for(char ch: s) q.push(ch);
        for(char ch : t){
            if( ch == q.front()){
                q.pop();
            }
        }
        if(q.empty()) return true;
        return false;

        
    }
};