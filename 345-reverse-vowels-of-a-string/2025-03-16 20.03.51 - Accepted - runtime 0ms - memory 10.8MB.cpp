class Solution {
public:
    string reverseVowels(string s) {
        set<char>st= {'a','e','i','o','u','A','E','I','O','U'};
        int left =0;
        int right= s.size()-1;
        while( left< right){
            if(st.find(s[left]) != st.end()){
                while(st.find(s[right])==st.end()) right--;
                if(left>right) break;
                char temp= s[left];
                s[left] = s[right];
                s[right]=temp;
                right--;
                

            }
            left++;
        }
        return s;
        
    }
};