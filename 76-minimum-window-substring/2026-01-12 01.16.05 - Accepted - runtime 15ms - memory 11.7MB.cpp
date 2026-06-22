class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq,window;
        for(char ch:t) freq[ch]++;
        int required = freq.size();
        int formed = 0;
        int left =0;
        int right =0;
        int n = s.size();
        int start =0;
        int minLen=INT_MAX;
        while(right<n){
            char ch = s[right];
            window[ch]++;
            if(freq.count(ch) && window[ch]==freq[ch]){
                formed++;
            }
            while(left<=right && formed==required){
                if(right-left+1<minLen){
                    minLen = right-left+1;
                    start =left;
                }
                char c=s[left];
                window[c]--;
                if(freq.count(c) && window[c]<freq[c]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};