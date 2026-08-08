class Solution {
public:
    int balancedStringSplit(string s) {
        int x=0;
        int cnt=0;
        for(char ch:s){
            if(ch=='L')x--;
            else x++;
            if(x==0)cnt++;
        }
        return cnt;
        
    }
};