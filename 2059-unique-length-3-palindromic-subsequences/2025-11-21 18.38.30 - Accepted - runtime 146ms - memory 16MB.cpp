class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt =0;
        vector<int> first(26,-1),last(26,-1);
        for(int i =0;i<s.size();i++){
            int c = s[i]-'a';
            if(first[c]==-1) first[c]=i;
            last[c]=i;
        }
        for(int c =0 ;c<26;c++){
            if(first[c]!=-1 && last[c]-first[c]>=2){
                unordered_set<char>st;
                for(int i = first[c]+1;i<last[c];i++){
                    st.insert(s[i]);
                }
                cnt+=st.size();
            }
        }
        return cnt;
    }
};