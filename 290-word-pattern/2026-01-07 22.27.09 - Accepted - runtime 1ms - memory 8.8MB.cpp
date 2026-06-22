class Solution {
public:
    bool wordPattern(string pattern, string s) {
       unordered_map<string,char>w2c;
       unordered_map<char,string>c2w;
       string word="";
       int i=0;
       for(auto ch:s) {
        if(i==pattern.size()) return false;
        if(ch!=' '){
            word+=ch;
        }else{
            if(w2c.find(word)!=w2c.end() && w2c[word]!=pattern[i]) return false;
            else if( c2w.find(pattern[i])!=c2w.end()&& c2w[pattern[i]]!=word ) return false;
            else{
                w2c[word]=pattern[i];
                c2w[pattern[i]]=word;
                i++;

            }
            word="";
        }
       }
       if (i == pattern.size()) return false;
     if(w2c.find(word)!=w2c.end() && w2c[word]!=pattern[i]) return false;
     if( c2w.find(pattern[i])!=c2w.end()&& c2w[pattern[i]]!=word ) return false;
       i++;
       return i==pattern.size();
    }
};