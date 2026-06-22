class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> seen;
        while(n!=1){
        if( seen.find(n)!=seen.end()) return false;
        seen.insert(n);
        int num = n;
        int sum =0;
        int rem =0;
            while(num ){
                rem = num%10;
                sum= sum + rem*rem;
                num = num/10;
            }
            n= sum;
            
        }
        return true;



    }
};