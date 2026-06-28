class Solution {
public:
    string maximumXor(string s, string t) {
        int one=0;
        int zero=0;
        for(char ch:t){
            if(ch=='1')one++;
            else zero++;
        }
        string ans ="";
        for(char ch:s){
            if(ch=='1'){
                if(zero>0){
                    ans+="1";
                    zero--;
                }else{
                    ans+="0";
                    one--;
                }
            }else{
                if(one>0){
                    ans+="1";
                    one--;
                }else{
                    ans+="0";
                    zero--;
                }
            }
            
        }
        return ans;
    }
};