class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int value = 0;

        for(int bit : nums){
            value = (value * 2 + bit) % 5;  // keep modulo small
            ans.push_back(value == 0);      // divisible by 5?
        }

        return ans;
    }
};
