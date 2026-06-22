class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt =0;
        bool firstCap =( word[0]>='A'&&word[0]<='Z')?true:false;
        for(char ch:word){
            if( ch>='A'&& ch<='Z')cnt++;
        }
        if( cnt==word.size()||cnt==0) return true;
        if(cnt ==1 && firstCap)return true;
        return false;

    }
};