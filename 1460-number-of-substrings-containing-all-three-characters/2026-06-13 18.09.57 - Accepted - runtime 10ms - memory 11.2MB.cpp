class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lastSeen ={-1,-1,-1};
        int n = s.size();
        int cnt =0;
        for(int i =0;i<n;i++){
            lastSeen [s[i]-'a']=i;
            cnt += 1+*min_element(lastSeen.begin(),lastSeen.end());
        }
        return cnt;
    }
};