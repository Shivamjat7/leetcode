class Solution {
    private:
   long long unsigned int  reversed =0;
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x== 0) return true;
        int temp=x;
        int num = x%10;
        reversed=reversed*10+num;
        isPalindrome(x/10);
        if(temp==reversed) return true; 
        return false;
    }
};