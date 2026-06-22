class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int minLevel=min(height[left],height[right]);
            int breadth=right-left;
            int current=minLevel*breadth;
            maxWater=max(current,maxWater);
            if(height[right]>height[left]) left++;
            else right--;
        }
        return maxWater;
        
    }
};