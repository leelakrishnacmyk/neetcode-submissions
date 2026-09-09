class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int profit=0;
     int mini=INT_MAX;
     for( int num: prices){
        mini=min(mini,num);
        profit=max(profit,num-mini);
     }
     return profit;
    }
};
