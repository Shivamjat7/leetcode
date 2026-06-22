class Solution {
public:
set<vector<int>>st;
    vector<int> temp;
    void f( int i ,vector<int>&nums){
        if(temp.size()>=2){
            st.insert(temp);
        }
       for(int idx = i;idx<nums.size();idx++){
    
         if(temp.empty() || nums[idx]>=temp.back()){
            temp.push_back(nums[idx]);
            f(idx+1,nums);
            temp.pop_back();
        }
       }
        

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        f(0,nums);
        

        return vector<vector<int>>(st.begin(),st.end());
    }
};