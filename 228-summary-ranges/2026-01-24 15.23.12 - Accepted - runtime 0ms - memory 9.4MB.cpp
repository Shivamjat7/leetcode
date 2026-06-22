class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string > res;
        if(nums.size()<1)return res;
        int prev=nums[0];
        int curr=nums[0];
        for(int i =1;i<nums.size();i++){
            if(curr+1 ==nums[i]){
                curr++;
                continue;
            }else if( curr == prev){
                res.push_back(to_string(curr));
               prev=curr=nums[i];
            }else{
                string str = to_string(prev)+ "->"+ to_string(curr);
                res.push_back(str);
                prev=curr=nums[i];
            }
        }
        if( curr == prev){
                res.push_back(to_string(curr));
            
            }else{
                string str = to_string(prev)+ "->"+ to_string(curr);
                res.push_back(str);
            }
        
        return res;
    }
};