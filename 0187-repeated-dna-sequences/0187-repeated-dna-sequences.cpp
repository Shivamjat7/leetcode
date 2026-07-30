class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int mask =0;
        unordered_map<char,int>mp ={{'A',0},{'C',1},{'G',2},{'T',3}};
        unordered_set<int>st,added;
        vector<string>ans;
        for(int i =0;i<s.size();i++){
            int bit = mp[s[i]];
            mask=(mask<<2)|bit;
            mask =mask&((1<<20)-1);
            if(i>=9 && st.count(mask) && !added.count(mask)){
                ans.push_back(s.substr(i-9,10));
                added.insert(mask);
            }
            if(i>=9)
            st.insert(mask);

        }
        return ans;
    }
};