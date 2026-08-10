class Solution {
public:
    bool compare(string &a,string &b){
        if(a.size()!=b.size()+1)return false;
        int i=0;
        int j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else i++;
        }
        return j==b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string &a,string &b){
    return a.size()<b.size();
});
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])&& dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};