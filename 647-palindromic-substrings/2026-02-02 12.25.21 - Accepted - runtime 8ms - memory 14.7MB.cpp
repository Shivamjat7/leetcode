class Solution {
public:
    int count(string s,int i){
        int cnt1 =0;
        int cnt2 =0;
        int left =i,right=i;
        while(left>=0 && right<s.size()&& s[left]==s[right]){
            cnt1++;
            left--;
            right++;
        }
        left =i,right=i+1;
        while(left>=0 && right<s.size()&& s[left]==s[right]){
            cnt2++;
            left--;
            right++;
        }
        return cnt1+cnt2;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i =0;i<s.size();i++){
            cnt+=count(s,i);
        }
        return cnt;
    }
};