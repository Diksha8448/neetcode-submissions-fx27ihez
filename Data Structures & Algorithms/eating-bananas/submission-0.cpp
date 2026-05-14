class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {

                hours += ceil((double)pile / mid);
            }

            // valid speed
            if (hours <= h) {

                ans = mid;
                right = mid - 1;
            }

            // too slow
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
