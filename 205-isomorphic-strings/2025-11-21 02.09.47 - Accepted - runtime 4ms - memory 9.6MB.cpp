class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> m,n;
        for(int i=0;i<s.size();i++){
           char a =s[i],b =t[i];
           if(m.count(a) && m[a]!=b||n.count(b)&& n[b]!=a)return false;
           m[a]=b;
           n[b]=a;
            
            
        }
        return true;
    }
};