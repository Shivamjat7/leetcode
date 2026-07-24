class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastIndex(26,-1);
        for(int i =0;i<s.size();i++){
            lastIndex[s[i]-'a']=i;
        }
        int start =0;
        int mx=0;
        vector<int>ans;
        for(int i =0;i<s.size();i++){
            int ch = s[i]-'a';
            if(lastIndex[ch]>mx)mx = lastIndex[ch];
            if(mx<=i){
                ans.push_back(i-start+1);
                start =i+1;
                mx=i+1;
            }
        }
        return ans;
    }
};