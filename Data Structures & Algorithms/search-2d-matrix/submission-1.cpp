class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // count of number of rows
       int rows=matrix.size();
       // count of number of columns
       int cols= matrix[0].size();
       // since we are considering it as 1-D array
       int left =0;
       int right=rows*cols-1;
       while(left<=right){
           int mid= left+(right-left)/2;
           // since mid is calculated as 1-D array so we need to 
           // recalculate the row and col accordingly
           int row=mid/cols;
           int col=mid%cols;
          // value according to new row col
           int value=matrix[row][col];
           if(value==target){
            return true;
           }
           else if(value<target){
            left=mid+1;
           }
           else{
            right=mid-1;
           }
       }
       return false;
    }
};
