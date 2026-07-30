class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(),dict.end(),[=](string a,string b){
            if(a.size()>b.size())return true;
            else if(a.size()==b.size() )return a<b;
            return false;
        });
        for(string word:dict){
            if(word.size()>s.size())continue;
            int i =0;
            int j=0;
            while(i<s.size()&&j<word.size()){
                if(s[i]==word[j]){
                    i++;
                    j++;
                }else i++;
            }
            if(j==word.size()){
                return word;
            }
        }
        return "";
    }
};