class Solution {
public:
    string convertToTitle(int columnNumber) {
     string res =""  ;
     while(columnNumber>0){
        columnNumber--;
        int n = columnNumber%26;
         columnNumber/=26;
         res = char(n+'A')+res;
     }
     return res;

    }
};