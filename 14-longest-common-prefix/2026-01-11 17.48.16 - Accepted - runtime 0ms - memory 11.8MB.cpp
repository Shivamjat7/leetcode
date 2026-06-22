class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        string lcp =strs[0];
        for(int i=1;i<strs.size();i++){
            int k=0;
            while(k<lcp.size()&& k<strs[i].size() && lcp[k]==strs[i][k]){
                k++;
            }
            lcp =lcp.substr(0,k);
            if(lcp.empty())return "";
        }
        return lcp;
    }
};