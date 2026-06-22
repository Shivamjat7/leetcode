class Solution {
public:
    int candy(vector<int>& rating) {
       int n = rating.size();
       vector<int>candy(n,1);
       for(int i =0 ; i<rating.size();i++) {
        if(i>0 && rating[i]>rating[i-1]){
            candy[i]=candy[i-1]+1;
        }
       }
       for(int i =rating.size()-1 ; i>=0;i--) {
        if(i<n-1 && rating[i]>rating[i+1]){
            candy[i]=max(candy[i],candy[i+1]+1);
        }
       }
       int cnt = accumulate(candy.begin(),candy.end(),0);
       return cnt;
    }
};