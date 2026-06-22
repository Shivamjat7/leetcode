class Solution {
public:
    vector<string>ans;
    string temp="";
    void f(int i ,string& s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        char ch = s[i];
    
        if(isdigit(ch)){
            temp.push_back(ch);
            f(i+1,s);
            temp.pop_back();
        }
        else{
            temp.push_back(toupper(ch));
            f(i+1,s);
            temp.pop_back();
            temp.push_back(tolower(ch));
            f(i+1,s);
            temp.pop_back();
            
        }


    }
    vector<string> letterCasePermutation(string s) {
        f(0,s);
        return ans;
    }
};