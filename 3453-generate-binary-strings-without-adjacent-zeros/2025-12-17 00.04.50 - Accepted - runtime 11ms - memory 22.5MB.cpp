class Solution {
    public:
    vector<string> ans;
    
    void backtrack(int n,string & temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back('1');
        backtrack(n,temp);
        temp.pop_back();
        if(temp.empty() || temp.back()!='0'){
         temp.push_back('0');
        backtrack(n,temp);
        temp.pop_back();
        }

    }

    vector<string> validStrings(int n) {
        string temp;
        backtrack(n,temp);
        return ans;
    }
};