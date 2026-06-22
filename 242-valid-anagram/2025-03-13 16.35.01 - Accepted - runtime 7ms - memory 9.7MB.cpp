class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> mpp;
        
        for(char ch : s){
            mpp[ch]++;
        }
        for( char ch: t){
            if(mpp.find(ch) != mpp.end()){
                mpp[ch]--;
                
            }else return false;
        }
        for(auto it : mpp){
            if(it.second !=0) return false;
        }
        return true;
        
    }
};