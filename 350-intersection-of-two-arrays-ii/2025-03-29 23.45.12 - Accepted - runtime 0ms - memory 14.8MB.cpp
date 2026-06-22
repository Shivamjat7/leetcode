class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        vector<int>res;
        for(int val:nums1) map[val]++;
        for(int val:nums2){
            if(map[val]){
                res.push_back(val);
                map[val]--;
                
            }
            
        }
        return res;
        
    }
};