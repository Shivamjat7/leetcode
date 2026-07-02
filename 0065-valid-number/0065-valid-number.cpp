class Solution {
public:
    bool isNumber(string s) {
        bool digit=false;
        bool exp=false;
        bool digitAfterExp=false;
        bool decimal = false;
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(isalpha(ch) && ch!='e' && ch!='E')return false;
            if((ch=='+' ||ch=='-')&& i>0 && (s[i-1]!='e' && s[i-1]!='E') )return false;
            if((ch=='+'||ch=='-')&& i!=0 && !exp) return false;
            if(isdigit(ch))digit =true;
            if((ch=='e'||ch=='E')){
                if(exp)return false;
                exp=true;
                if(!digit) return false;
            }
            if(ch=='.'){
                if(decimal)return false;
                decimal=true;
            }
            if(exp){
                if(ch=='.')return false;
                if(isdigit(ch))digitAfterExp=true;
            }
        }
        bool ans=true;
        if(exp) ans= ans && digitAfterExp;
        return ans&&digit;


    }
};