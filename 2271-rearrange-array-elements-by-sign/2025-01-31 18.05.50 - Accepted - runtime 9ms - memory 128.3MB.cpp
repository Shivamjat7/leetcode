class Solution {
public:
  vector<int> rearrangeArray(vector<int> & nums)  {
    vector <int> temp(nums.size());
    int j=0,k=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            temp[j] = nums[i];
            j=j+2;
        }
        else{
             temp[k]= nums[i];
            k=k+2;

        }

    }
    return temp;
} 
};