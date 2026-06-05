class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int stone:stones){
          pq.push(stone);
        }
        while(pq.size()>1){
            int y=pq.top(); // first largest
            pq.pop();

            int x=pq.top(); // second largest
            pq.pop();

            if(y!=x){
                pq.push(y-x);
            }
        }
        return pq.empty()?0:pq.top();
    }
};
