class Solution {
public:
    string reversePrefix(string s, int k) {
        int n=s.size();
        n=k<n?k:n;
        reverse(s.begin(),s.begin()+n);
        return s;
    }
};