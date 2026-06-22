class Solution {
    
public:
    string reverseWords(string s) {
        int j =0;
       for(int i =0;i<=s.size();i++){
         if((i>0 && s[i]==' ' && i>j)||i==s.size()){
            int k = i-1;
            while(j<k){
                swap(s[k],s[j]);
                k--;
                j++;
            }
            j=i+1;
         }
       } 
        return s;
    }
};