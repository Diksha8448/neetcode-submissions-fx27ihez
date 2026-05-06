class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // we will make set to store unique values
        unordered_set<int>s(nums.begin(),nums.end());
         int longest=0;
        // iterate through set
        for(int num:s){

            //  check if previous exist 
            // if it is the starting of the sequence
            if(s.find(num-1)==s.end()){
                int current =num;
                int count=1;

                while(s.find(current+1)!=s.end()){
                    current++;
                    count++;
                }
                longest=max(longest,count);

            }
        }
        return longest;
    }
};
