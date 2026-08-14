class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>window;
        int left =0;
        int right =0;
        int ans =0;
        while(right<s.size()){
            window[s[right]]++;
            while(window[s[right]]>2){
               window [s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};