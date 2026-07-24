class Solution {
public:
    int partitionString(string s) {
        int mask =0;
        int cnt =1;
        for(char ch:s){
            int bit = 1<<(ch-'a');
            if(mask &bit){
                cnt++;
                mask =0;
            }
            mask|=bit;
        }
    
        return cnt;
    }
};