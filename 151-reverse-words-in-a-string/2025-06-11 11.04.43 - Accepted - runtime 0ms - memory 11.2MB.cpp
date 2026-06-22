class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string word="";
        for(auto ch:s){
            if(ch !=' '){
                word=word+ch;
            }else if(!word.empty()){
                vec.push_back(word);
                word="";
            }
        }
        if(!word.empty()) vec.push_back(word);
        reverse(vec.begin(),vec.end());
        string str="";
        for(int i=0;i<vec.size();i++){
            str+=vec[i];
            if(i!=vec.size()-1){
                str+=' ';
            }
        }
        return str;
    }
};