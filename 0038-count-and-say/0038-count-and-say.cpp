class Solution {
public:
    string rle(string s){
        string ans ="";
        int cnt=1;
        for(int i =1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{

                ans+=to_string(cnt)+s[i-1];
                cnt=1;
            }
        }
        ans+=to_string(cnt)+s.back();
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)return "1";
        string s= countAndSay(n-1);
        return rle(s);
    }
};