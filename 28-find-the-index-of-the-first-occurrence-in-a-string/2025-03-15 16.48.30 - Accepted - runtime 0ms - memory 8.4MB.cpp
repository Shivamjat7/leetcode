class Solution {
public:
    int strStr(string haystack, string needle) {
        int index =-1;
        
        for( int i =0;i<haystack.size();i++){
            if( haystack[i]==needle[0]){
                int j=0;
                while( j<needle.size()){
                    if( haystack[i+j] != needle[j]) break;
                    j++;
                }
                if(j == needle.size()) return i;

            

            }
        }
        return index;
    }
};