class Solution {
public:
    bool check(int num){
        int n = num;
        while(n>0){
            int d = n%10;
            if(d==0 || num%d!=0)return false;
            n=n/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int  i = left ;i<=right;i++){
            if(check(i))ans.push_back(i);
        }
        return ans;
    }
};