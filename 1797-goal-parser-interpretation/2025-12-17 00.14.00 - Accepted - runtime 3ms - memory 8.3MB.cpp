class Solution {
public:
    string interpret(string command) {
        int i=0;
        string ans;
        while( i<command.size()){
            if(command[i]=='G'){
                ans.push_back('G');
                i++;
            }else if (i+1<command.size() && command[i]=='(' && command[i+1]==')'){
                ans.push_back('o');
                i+=2;
            }else {
                ans+="al";
                i+=4;
            }
        }
        return ans;
    }
};