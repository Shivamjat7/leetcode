class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int l =0,r =0,n =s.size(),maxFreq=0;
        int maxLength=0;

        while(r<n){
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);
            while(r-l+1 -maxFreq>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxFreq<=k){
                maxLength = max(maxLength,r-l+1);
            }
            r++;

        }
        return maxLength;
    }
};