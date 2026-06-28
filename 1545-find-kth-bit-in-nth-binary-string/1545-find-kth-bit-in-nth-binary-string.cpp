class Solution {
public:
    string invert(string s){
        for(char &ch:s){
            if(ch=='1')ch='0';
            else ch='1';
        }
        return s;
    }
    string build(int n){
        if(n==1) return "0";
        string prev = build(n-1);
        string rev=invert(prev);
        reverse(rev.begin(),rev.end());
        return prev +"1"+ rev;
    }
    char findKthBit(int n, int k) {
        string s =build(n);
        return s[k-1];
    }
};