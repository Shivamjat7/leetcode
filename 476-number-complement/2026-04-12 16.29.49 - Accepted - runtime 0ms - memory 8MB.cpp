class Solution {
public:
    int findComplement(int num) {
        int cnt =0;
        int n = num;
        int i =0;
        while(n){
            if(n&1){
                i++;
                cnt =i;
            }else i++;
            n = n>>1;
        }
        num = ~num;
        return num&((long)(1<<cnt)-1);
    }
};