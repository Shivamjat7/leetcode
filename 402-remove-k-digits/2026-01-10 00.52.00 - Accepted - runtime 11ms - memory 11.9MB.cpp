class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch:num){
            while(!st.empty()&& k>0 && st.top()>ch){
                k--;
                st.pop();
            }
            st.push(ch);


        }
        if(st.empty())return "0";
        string res="";
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);
         return res.empty()?"0":res;

    }
};