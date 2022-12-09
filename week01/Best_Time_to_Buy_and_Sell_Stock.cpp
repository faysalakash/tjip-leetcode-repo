class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // TC: O(N) N = prices size
    // MC: O(1)

    int minBuy = INT_MAX;
    int profit = 0;

    for(auto i : prices){
      minBuy = min(minBuy, i);

      if(i > minBuy) profit = max(profit, i - minBuy);
    }

    return profit;
  }
};