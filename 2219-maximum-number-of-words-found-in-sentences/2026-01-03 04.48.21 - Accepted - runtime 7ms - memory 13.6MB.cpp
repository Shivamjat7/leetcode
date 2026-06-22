class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=0;
        for(auto sen : sentences){
            int cnt =1;
            for(char ch:sen){
                if(ch==' ')cnt++;
            }
            mx= max(cnt,mx);
        }
        return mx;
    }
};