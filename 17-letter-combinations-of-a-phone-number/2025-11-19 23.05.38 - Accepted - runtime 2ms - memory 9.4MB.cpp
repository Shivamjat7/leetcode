class Solution {
vector<string> ans;
string temp;
void backtracking(int idx,string& digits, vector<string>&mpp){
    if(idx==digits.size()){
        ans.push_back(temp);
        return;
    }
    string letters = mpp[digits[idx] -'2'];
    for(char ch: letters){
        temp.push_back(ch);
        backtracking(idx+1,digits,mpp);
        temp.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        vector<string>mpp ={{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
        backtracking(0,digits,mpp);
        return ans;

      
        
    }
};