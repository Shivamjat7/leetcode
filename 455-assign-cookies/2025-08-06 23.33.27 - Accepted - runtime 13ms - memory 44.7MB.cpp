class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i =0,j=0;
        int cnt =0;
        while(j<s.size() && i<g.size()){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }else j++;
        }
        return cnt;
        
    }
};