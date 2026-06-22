class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
        

        
    }
    void reverse(vector<int> &arr,int left, int right){
    while(left<right){
        int temp= arr[left];
        arr[left]= arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    }
};