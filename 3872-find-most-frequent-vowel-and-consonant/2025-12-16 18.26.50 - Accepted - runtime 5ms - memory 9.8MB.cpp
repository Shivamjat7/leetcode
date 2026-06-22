class Solution {
public:
    int maxFreqSum(string s) {
     unordered_map<char,int>mp;
     for(char ch: s)   mp[ch]++;
     int maxConst=0;
     int maxVowel=0;
     for(auto it: mp){
        char ch= it.first;
        int freq=it.second;
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            maxVowel= max(maxVowel,freq);
        }else maxConst=max(maxConst,freq);
     }
     return maxVowel+maxConst;
    }
};