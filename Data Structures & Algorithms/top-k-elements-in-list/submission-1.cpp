class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // make a map 
        unordered_map<int,int>mp;
        // count the frequency .. must step 
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        // since we need top k not the element which has occured k times
        // so for that we will store in priority queue

        // we will use min-heap here 
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;

        // we will iterate through mp and keep pushing values in pq
        for(auto it:mp){
            //frequency first value later
            pq.push({it.second,it.first});

            // check if heap size doesn't exceed k 
            if(pq.size()>k){
                pq.pop();
            }
        }

        // extract result 
        // we will iterate the priority queue now 
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;


    }
};
