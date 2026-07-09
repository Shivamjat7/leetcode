class Solution {
public:
    using ull = unsigned long long;
    ull BASE = 131;
    ull MOD = 1e9+7;
    int bestLen =0;
    int bestStart =-1;
    vector<ull>power,pref;
    void init(int n,string s){
        power.assign(n+1,1);
        pref.assign(n+1,0);
        for(int i=0;i<n;i++){
            power[i+1]=power[i]*BASE%MOD;
            pref[i+1] = ((pref[i]*BASE) +(s[i]-'a'+1))%MOD;
        }
    }
    ull getHash(int l,int r){
        return (pref[r+1]-pref[l]*power[r-l+1]%MOD +MOD)%MOD;
    }
    bool check(int len,string &s){
        unordered_map<ull,vector<int>>mp;
        int n = s.size();
        for(int i=0;i+len<=n;i++){
            ull h = getHash(i,i+len-1);
            if(mp.contains(h)){
                for(int pos:mp[h]){
                    if(s.compare(pos,len,s,i,len)==0){
                        bestStart =i;
                        return true;
                    }
                }
            }
            mp[h].push_back(i);
        }
        return false;
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        init(n,s);
        int low =0,high=n;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(check(mid,s)){
                bestLen =mid;
                low = mid+1;
            }else high =mid-1;
        }
        return bestStart!=-1?s.substr(bestStart,bestLen):"";
    }
};