class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(),allowed.end());
        int cnt=0;
        for(string word: words ){
            for(char ch: word){
                if( !st.count(ch)){
                    cnt++;
                    break;
                }
                
            }
        }
        return words.size()-cnt;
    }
};