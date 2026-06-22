class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int mn = *min_element(nums.begin(),nums.end());
        return sum-mn*n;
    }
};