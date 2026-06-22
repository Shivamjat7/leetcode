class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n =nums.size();
    
        long first = LONG_MIN;
        long second=LONG_MIN;
        long third =LONG_MIN;
        for(int val : nums){
            if(val==first||val==second||val==third) continue;
            if(val>first){
                third =second;
                second = first;
                first=val;
            
            }
             if(val>second && val<first) {
                third =second;
                second = val;
            }
             if( val>third && val<second) third = val;
        }
        return third==LONG_MIN?first:third;
    }
};