class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       map<int,int> mpp; 
        for( int val: nums){
            mpp[val]++;
        }
        vector<int> arr;
        for ( int i =1 ;i<=nums.size();i++){
            if( mpp.find(i)==mpp.end()) arr.push_back(i);
        }
        return arr;
        
    }
};