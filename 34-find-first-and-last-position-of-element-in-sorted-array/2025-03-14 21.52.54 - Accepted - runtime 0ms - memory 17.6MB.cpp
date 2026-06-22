class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurence(nums,target),lastOccurence(nums,target)};
        
    }
    int firstOccurence(vector<int> &arr, int num){
    int low =0, high = arr.size()-1;
    int result =-1;

    while( low<=high){
        int mid = low + ( high-low)/2;
        if(arr[mid] == num){
            result = mid;
            high = mid-1;  // to check any other possibilities in left;
        }else if ( arr[mid] < num){
            low= mid+1;
        }else{
            high =  mid -1;
        }
    }
    return result;
}

int lastOccurence( vector<int> & arr, int num){
    int low =0, high = arr.size()-1;
    int result =-1;

    while( low<=high){
        int mid = low + ( high-low)/2;
        if(arr[mid] == num){
            result = mid;
            low = mid+1; // to check any other possibilities in right;
        }else if ( arr[mid] < num){
            low= mid+1;
        }else{
            high =  mid -1;
        }
    }
    return result;
}
};