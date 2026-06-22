class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size(),i=n-1;
        if(digits[n-1]!=9){
            digits[n-1]++;
        }else{
            while(i>=0 &&digits[i]==9){

                digits[i]=0;
                i--;
            }
            if(i>=0){
            digits[i]++;
            }else{
                digits[0]=1;
                digits.push_back(0);
            }

            

        }
        return digits;
        
    }
};