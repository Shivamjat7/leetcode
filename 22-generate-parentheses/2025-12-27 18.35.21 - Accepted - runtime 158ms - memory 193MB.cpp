class Solution {
public:
   
    void backtrack(int n,string & temp,vector<string>&ans){
        if(temp.size()==2*n){
            if(isValid(temp))ans.push_back(temp);
            return ;
        }
        temp.push_back('(');
        backtrack(n,temp,ans);
        temp.pop_back();
        temp.push_back(')');
        backtrack(n,temp,ans);
        temp.pop_back();
    }
    bool isValid(string str){
         stack<char>st;
         for(char ch:str){
            if(ch=='(')st.push(ch);
            else{
              if(st.empty())return false;
             st.pop();
            }
         }
         return st.empty();
    }
    vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string temp;
    backtrack(n,temp,ans);
    return ans;
        


        
    }
};