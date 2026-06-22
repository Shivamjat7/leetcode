class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [s,level]=q.front();
            q.pop();
            if(s==endWord)return level;
            for(int i=0;i<s.size();i++){
                char original = s[i];
               for(char ch='a';ch<='z';ch++){
                   s[i]=ch;
                   if(st.count(s)){
                    st.erase(s);
                    q.push({s,level+1});
                   }
               }
               s[i]=original;
            }

        }
        return 0;
    }
};