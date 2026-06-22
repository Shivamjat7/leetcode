class Solution {
public:
    pair<int,int> f(int l,int r,string s){
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            r++;
            l--;
        }
        return {l+1,r-1};
    }
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int,int> longest={0,0};
        for(int i=0;i<n;i++){
            auto p1=f(i,i,s);
            if(p1.second-p1.first>longest.second-longest.first)
            longest =p1;
            auto p2=f(i,i+1,s);
            if(p2.second-p2.first>longest.second-longest.first)
            longest =p2;
        }
        string res="";
        auto[l,r]=longest;
        for(int i=l;i<=r;i++){
            res+=s[i];
        }
        return res;
    }
};