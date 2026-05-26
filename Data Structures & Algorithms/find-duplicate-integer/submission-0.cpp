class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we have to treat every array as linked list
        // we can't use hashmap or sorting because it wants o(1) space
        // and no modification
        // so will use floyd's algorithm
        // slow fast pointer

        int slow=nums[0];
        // slow=head;
        int fast=nums[0];
        // fast=head;
        
        // detect cycle exists
        // Phase 1
        do{
           slow=nums[slow];
           // slow=slow->next;
           fast=nums[nums[fast]];
           // fast=fast->next->next;
        }while(slow!=fast);
        
        //find cycle entrance
        //Phase2

        //cycle entrance = duplicate number
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;



    }
};
