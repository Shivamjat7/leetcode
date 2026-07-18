class Solution {
public:
    bool comparator(int a,int b){
        string num1 = to_string(a)+to_string(b);
        string num2 = to_string(b)+to_string(a);
        return num1>num2;
        
     
    
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return comparator(a,b);
        });
        string ans ="";
        bool flag =false;
        for(auto num:nums){
            if(num)flag =true;
            ans+=to_string(num);
        }
        return flag?ans:"0";
    }
};