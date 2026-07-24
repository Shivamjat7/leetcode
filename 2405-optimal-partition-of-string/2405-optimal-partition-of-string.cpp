class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int cnt =0;
        for(char ch:s){
            if(st.count(ch)){
                cnt++;
                st.clear();
            }
            st.insert(ch);
        }
        if(!st.empty())cnt++;
        return cnt;
    }
};