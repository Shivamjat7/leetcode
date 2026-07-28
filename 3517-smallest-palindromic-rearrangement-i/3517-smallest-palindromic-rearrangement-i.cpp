class Solution {
public:
    string smallestPalindrome(string s) {
        
        string ans="";
        int n = s.size();
        if(n<2)return s;
        int i=0;
        for(;i<n/2;i++)ans+=s[i];
        sort(ans.begin(),ans.end());
        string rev="";
        for(int i=ans.size()-1;i>=0;i--) rev+=ans[i];
        if(n%2 && n>1)ans+=s[i];
        ans+=rev;
        return ans;
    }
};