class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cnt=0;
        int n= nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i);
        }
        int top=nums[0];
        while(cnt<k && !nums.empty()){
            top = nums[0];
            
            cnt++;
            swap(nums[0],nums.back());
            nums.pop_back();
            heapify(nums,0);

        }
        return top;
    }
    void heapify(vector<int> &arr,int i){
        int l =2*i+1,r=2*i+2, largest=i;
        if(l<arr.size()&& arr[l]>arr[largest])largest=l;
        if(r<arr.size()&& arr[r]>arr[largest])largest=r;
        if(largest !=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest);
        }

    }

    
};