class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq;
        string target = "balloon";
        for(char ch:text) freq[ch]++;
        int cnt=0;
        bool flag =true;
        while(flag){
        for(char ch:target){
            if(freq[ch]>0){
                freq[ch]--;
            }else {
                flag =false;
                break;
            };
        }
        if(flag)cnt++;
        }
        return cnt;


    }
};