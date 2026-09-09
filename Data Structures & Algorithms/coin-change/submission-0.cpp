class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans=solve(0,coins,amount,dp);
       return (ans>=1e9)? -1:ans;
        
    }
    int solve(int index,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if (amount==0){
            return 0;
        }
        if (index==coins.size()){
            return 1e9;
        }
        if (amount<0){
            return 1e9;
        }if (dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int take=1+solve(index,coins,amount-coins[index],dp);
        int nottake=solve(index+1,coins,amount,dp);
        return dp[index][amount]= min(take,nottake);
    }
};
