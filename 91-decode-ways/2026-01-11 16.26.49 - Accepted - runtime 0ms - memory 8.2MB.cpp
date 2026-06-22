class Solution {
public:

    int numDecodings(string s) {
       int n = s.size();
       int prev2=1,prev1=1,curr=0;
       for(int i=1;i<=n;i++){
            if(s[i-1]!='0'){
             curr+=prev1;
            }
            if(i>1){
            int num =0;
            num= (s[i-1-1]-'0')*10 + (s[i-1]-'0');
                 if(num>=10 && num<=26){
                 curr+=prev2;
                    }
                     }
            prev2=prev1;
            prev1=curr;
            curr=0;
       }
       return prev1;
    }
};