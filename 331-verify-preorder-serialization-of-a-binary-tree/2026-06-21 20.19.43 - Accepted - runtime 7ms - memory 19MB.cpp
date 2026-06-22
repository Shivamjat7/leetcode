class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string>nodes;
        string curr ="";
        for(char ch:preorder){
            if(ch==','){
                nodes.push_back(curr);
                curr="";
            }else{
                curr+=ch;
            }
        }
        nodes.push_back(curr);
        stack<string>st;
        for(auto & x:nodes){
            st.push(x);
            while(st.size()>=3){
                string a = st.top();st.pop();
                string b = st.top();st.pop();
                string c = st.top();st.pop();
                if(a=="#"&& b=="#" && c!="#"){
                    st.push("#");
                }else{
                    st.push(c);
                    st.push(b);
                    st.push(a);
                    break;
                }
            }
        }
        return st.size()==1 && st.top()=="#";
    }
};