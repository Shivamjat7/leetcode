
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size()==0)return {};
        unordered_map<string, int> mp, window;
        for (auto word : words)
            mp[word]++;

        int len = words[0].size();
        vector<int> ans;
        
        for(int offset=0;offset<len;offset++){
        int left = offset, right = offset;
        int total =words.size();
        int matched = 0;
        while (right + len <= s.size()) {
            string word = s.substr(right, len);
            if (!mp.count(word)) {
                window.clear();
                left = right + len;
                right += len;
                matched =0;
                continue;
            }
            window[word]++;
            matched++;
            while (window[word] > mp[word]) {
                string wd = s.substr(left, len);
                window[wd]--;
                if(window[wd]==0)window.erase(wd);
                left = left + len;
                matched--;
            }
            if(matched ==total){
                ans.push_back(left);
                string wd = s.substr(left,len);
                window[wd]--;
                if(window[wd]==0)window.erase(wd);
                left = left + len;
                matched --;
                
            }
          
            right = right + len;
        }
        window.clear();
        }
        return ans;
    }
};