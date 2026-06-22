class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i =0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for( int j=i+1;j<nums.size();j++){
            
                int x = j+1;
                int y= nums.size()-1;
                while(x<y){
                    
                 long long  sum = (long long )nums[i]+nums[j]+nums[x]+nums[y];
                    if( sum == target){
                        
                        vector<int> vec ={nums[i],nums[j],nums[x],nums[y]};
                        if(st.find(vec)==st.end()) ans.push_back(vec);
                        st.insert(vec);
                        
                        
                        x++;
                        y--;
                    }else if( sum> target ) y--;
                    else x++;
                }
            }
        }
        return ans;

        
    }
};