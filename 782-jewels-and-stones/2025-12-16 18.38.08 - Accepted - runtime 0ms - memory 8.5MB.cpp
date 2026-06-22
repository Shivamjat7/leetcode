class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>st;
         st.insert(jewels.begin(),jewels.end());
        int cnt =0;
        for(char ch: stones){
            if(st.count(ch)){
                cnt++;
            }
        }
        return cnt;
    }
};