class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int minPrice=prices[0];
      int maX=0;
      for(int i=1;i<prices.size();i++){
          //calculate profit
          int profit=prices[i]-minPrice;

          //update the profit
          if(profit>maX){
            maX=profit;
          }
          //update the minimum 
           if(prices[i]<minPrice){
            minPrice=prices[i];
           }

      }
      return maX;
    }
};
