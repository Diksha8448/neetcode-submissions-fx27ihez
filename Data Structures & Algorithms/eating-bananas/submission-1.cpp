class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());

        //initialize ans with the maximum speed because it is
        // guaranteed to be a valid solution
        // our work is to minimize so hence the whole question
        int ans=right;

        while(left<=right){
            // we need to find k because that's what the question is 
            // somewhere in between of left and right
            // we use this(right-left)thing to avoid integer overflow
            int mid=left+(right-left)/2;
            // numbers of hours =piles/k;
            long long hours=0;
            for(int pile:piles){
                hours+=ceil((double)pile/mid);
            }
            // soul purpose is to check if (total hours <h)
            if(hours<=h){
                ans=mid;

                // try smaller speed 
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
