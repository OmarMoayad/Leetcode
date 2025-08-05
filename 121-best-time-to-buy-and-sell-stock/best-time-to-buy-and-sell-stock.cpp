class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy=INT_MAX;
        int maxprofit = 0;  
        for(int i=0;i<prices.size();i++){
        if(prices[i]<minbuy){
        minbuy=prices[i];
        }
        else if(prices[i] - minbuy > maxprofit) {
                maxprofit = prices[i] - minbuy;  
            }
        }
        return maxprofit;
        }
    };
