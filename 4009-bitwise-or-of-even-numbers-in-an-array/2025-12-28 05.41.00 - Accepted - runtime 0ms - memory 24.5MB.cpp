class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
       int x =0;
       for(int num:nums) {
        if(num%2==0) x=x|num;
       }
       return x;
    }
};