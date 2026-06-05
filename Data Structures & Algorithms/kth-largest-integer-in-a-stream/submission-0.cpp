class KthLargest {
private:
    int k;
    // this is for minHeap means minimum will be top 
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // priority_queue<int> pq; this is for maxHeap means max 
    // will be on top
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
         if(minHeap.size()>k){
                minHeap.pop();
        }
        return minHeap.top();
    }
};
