class Solution {
public:
    bool checkRecord(string s) {
        int absent=0;
        char day1,day2,day3;
        for(char ch:s){
            day3=day2;
            day2=day1;
            day1=ch;
            if(day1=='L'&&day2=='L'&& day3=='L')return false;
            if(ch=='A')absent++;
            if(absent>=2)return false;

        }
        return true;
    }
};