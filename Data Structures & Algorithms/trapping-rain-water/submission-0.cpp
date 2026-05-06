class Solution {
public:
    int trap(vector<int>& height) {
        // we need left right
        // we need maxLeft maxRight
        int left=0;
        int right=height.size()-1;
        int maxLeft=0,maxRight=0;
        int water=0;

        while(left<right){
            if(height[left]<height[right]){
               if(height[left]>=maxLeft)
                  maxLeft=height[left];
               else{
               water+=maxLeft-height[left];
               }
               left++;
            }
            else{
               if(height[right]>=maxRight)
                  maxRight=height[right];
               else{
                  water+=maxRight-height[right];
               }
               right--;
            }
            
        }
        return water;

    }
};
