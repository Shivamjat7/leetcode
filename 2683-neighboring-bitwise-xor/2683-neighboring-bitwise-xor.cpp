class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x =0;
        for(int val:derived) x=x^val;
        return x==0;
    }
};