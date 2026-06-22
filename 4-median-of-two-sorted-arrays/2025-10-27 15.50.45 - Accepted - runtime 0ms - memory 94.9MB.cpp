class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int n = num1.size();
        int m = num2.size();
        if(n>m)return findMedianSortedArrays(num2,num1);

        int low = 0,high =n;
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = (m+n+1)/2-cut1;

            int left1 = cut1==0?INT_MIN:num1[cut1-1];
            int right1 = cut1==n?INT_MAX:num1[cut1];
            int left2= cut2==0?INT_MIN:num2[cut2-1];
            int right2 = cut2==m?INT_MAX:num2[cut2];

            if(left1<=right2 && left2<=right1){
                if((m+n)%2==0){
                    return( max(left1,left2)+min(right1,right2))/2.0;
                }else{
                    return  max(left1,left2);
                }
            }else if( left1>right2){
                high=cut1-1;
            }else low= cut1+1;

        }
    return 0.0;
    }
};