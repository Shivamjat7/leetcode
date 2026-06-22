class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>groups;
        vector<vector<string>> result;
        for(string s:strs){
            string key =s;
            sort(key.begin(),key.end());
            groups[key].push_back(s);
        }
        for(auto it:groups){
            result.push_back(it.second);
        }
        return result;
        
    }
};