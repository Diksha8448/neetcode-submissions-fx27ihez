class Solution {
public:
    int maxArea(vector<int>& heights) {
       int left=0;
       int right=heights.size()-1;
       int maxSum=0;
       while(left<right){
          // area = length * breadth
          int length=right-left;
          int breadth=min(heights[left],heights[right]);
          int area=length*breadth;
          maxSum=max(maxSum,area);
          if(heights[left]<heights[right]){
             left++;
          }
          else{
            right--;
          }
       }
       
       return maxSum;
    }
};
