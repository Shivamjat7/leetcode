class Solution {
public:
    vector<int>arr;
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    int pick(int target) {
        int cnt =0;
        int ans =0;
        for(int i =0;i<arr.size();i++){
            if(arr[i]==target){
                cnt++;
                if(rand()%cnt ==0)ans =i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */