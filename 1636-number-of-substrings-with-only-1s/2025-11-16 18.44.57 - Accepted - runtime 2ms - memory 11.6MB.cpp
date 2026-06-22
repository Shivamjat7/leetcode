class Solution {
public:
    int numSub(string s) {
        int left =0;
        long long ans =0;
        int MOD = 1e9+7;
        for(int right =0;right<s.size();right++){
            if(s[right]=='0')left=right;
            while(s[left]=='0') left++;
          if(s[right]=='1') ans +=( (right -left+1)%MOD);
        }
        return ans%MOD;
    }
};