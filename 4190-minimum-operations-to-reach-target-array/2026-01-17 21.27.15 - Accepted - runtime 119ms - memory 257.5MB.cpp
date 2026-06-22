class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int>st;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
    
            if(nums[i]==target[i] || st.count(nums[i]))continue;
            else {
                cnt++;
                st.insert(nums[i]);
            }
        }
        return cnt;
    }
};