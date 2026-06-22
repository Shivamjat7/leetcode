class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid1=0, i=0;
        int mid2=nums.size()-1;

        while(mid1<mid2 && i<=mid2 ){
            if( nums[i]==0){
                int temp = nums[i];
                nums[i]= nums[mid1];
                nums[mid1]= temp;
                mid1++;
            i++;
            }else if( nums[i]==2){
                int temp = nums[i];
                nums[i] = nums[ mid2];
                nums[mid2] = temp;
                mid2--;
            }else i++;
        

        }
        
    }
};