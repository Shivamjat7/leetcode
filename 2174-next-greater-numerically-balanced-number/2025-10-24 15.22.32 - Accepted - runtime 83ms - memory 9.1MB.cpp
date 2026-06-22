class Solution {
private:
    bool isBeutifulNum(int n){
        int freq[10]={0};
        int temp = n;
        while(temp>0){
            freq[temp%10]++;
            temp/=10;
        }
        for(int d=0;d<=9;d++){
            if(freq[d] && freq[d]!=d) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        while(true){
            n++;
            if(isBeutifulNum(n)) return n;
        }
        return -1;
    }
};