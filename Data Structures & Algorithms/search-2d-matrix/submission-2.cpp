class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right=matrix.size()-1 ;
        int n=matrix[0].size();
        while(left<=right){
            int mid=(left+right)/2;
            if (matrix[mid][0]<=target &&  matrix[mid][n-1]>=target){
                int low=0;
                int high=n-1;
                while(low<=high){
                    int mid1=(low+high)/2;
                    if (matrix[mid][mid1]<target){
                        low=mid1+1;
                    }else if (matrix[mid][mid1]>target){
                        high=mid1-1;
                    }else if (matrix[mid][mid1]==target) {
                        return true;
                    }
                  
                } 
                return false;

            }else if (matrix[mid][0]>target){
               right=mid-1;
            }else{
              left=mid+1;
            }
        }
        return false;
    }
};
