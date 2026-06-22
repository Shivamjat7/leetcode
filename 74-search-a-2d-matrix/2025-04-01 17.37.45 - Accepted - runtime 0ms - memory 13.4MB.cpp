class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up =0,down =matrix.size()-1;
        int low =0, high = matrix[0].size()-1;
        while(up<=down){
            int mid1= up + (down-up)/2;
            if(target>=matrix[mid1][low] && target<=matrix[mid1][high]){
                while(low<=high){
                    int mid2 = low +(high-low)/2;
                    if(matrix[mid1][mid2]== target ) return true;
                    else if( matrix[mid1][mid2]<target) low = mid2+1;
                    else high = mid2-1;
                }
        }else if( target < matrix[mid1][low]) down = mid1-1;
        else up = mid1+1;

        }
        return false;

        
    }
};