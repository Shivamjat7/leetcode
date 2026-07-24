class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp,window;
        for(char ch:p)mp[ch]++;
        int total = p.size();
        int matched =0;
        vector<int>ans;
        int left =0,right =0;
        while(right<s.size()){
            char ch = s[right];
            window[ch]++;
            matched++;
            if(!mp.contains(ch)){
                window.clear();
                left=right+1;
                right++;
                matched=0;
                continue;
            }
            while(window[ch]>mp[ch]){
                window[s[left]]--;
                matched--;
                left++;
            }
            if(matched ==total){
                ans.push_back(left);
            }
            right++;
        }
        
       
        return ans;
    }
};