class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        if(!st.count(endGene))return -1;
        queue<pair<string,int>>q;
        q.push({startGene,0});
        st.erase(startGene);
        char charSet []={'A','C','G','T'};
        while(!q.empty()){
            auto[str,level]=q.front();
            q.pop();
            if(str==endGene)return level;
            for(auto &x:str){
                char original = x;
                for(auto ch:charSet){
                    if(ch==x)continue;
                    x=ch;
                    if(st.count(str)){
                        q.push({str,level+1});
                        st.erase(str);
                    }
                }
                x=original;
                
            }
        }
        return -1;
    }
};