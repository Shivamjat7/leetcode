class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        int n =s.size();
        for(char ch:s){
            if(ch=='1')ones++;
        }
        string res="";
        while(ones>1){
            res =res+'1';
            ones--;
            n--;
        }
        while(n>1){
            res=res+'0';
            n--;
        }
        res+='1';
        return res;
    }
};