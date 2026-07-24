class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>st;
        string str ="";
        vector<string>ans;
        for(int i =0;i<s.size();i++){
            str+=s[i];
            if(st.count(str))continue;
            ans.push_back(str);
            st.insert(str);
            str ="";

        }
        return ans;
    }
};