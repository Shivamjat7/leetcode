class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n = s.size();
        vector<int> vis(26,0);
        vector<int> last(26,-1);
        for(int i =0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        
        for(int i=0;i<n;i++){
            if(vis[s[i]-'a'])continue;
            while(!ans.empty() && ans.back()>s[i] && last[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            };
        
            ans.push_back(s[i]);
            vis[s[i]-'a']=1;
            

        }
        return ans;
    }
};