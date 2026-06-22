class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>vec(numRows,"");
        int n = s.size();
        bool goingDown=false;
        int currRow=0;
        for(char ch:s){
            vec[currRow]+=ch;
            if(currRow==0 || currRow ==numRows-1) goingDown =!goingDown;
            currRow += goingDown?+1:-1;
        }
        string ans ="";
        for(string str:vec){
            for(char ch:str){
                ans+=ch;
            }
        }
        return ans;
    }
};