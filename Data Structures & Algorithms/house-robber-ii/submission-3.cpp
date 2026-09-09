class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
         vector<int> dp1(n, -1);
        int p=solve(nums,0,n-2,dp1);
         vector<int> dp2(n, -1);
        int q=solve(nums,1,n-1,dp2);
        return max(p,q);
    }
    int solve( vector<int>& nums, int l,int r,vector<int>&dp){
        if (l>r){
            return 0;
        }
        if (dp[l]!=-1){
            return dp[l];
        }
       int  rob=nums[l]+solve(nums,l+2,r,dp);
       int  notr=solve(nums,l+1,r,dp);
        return  dp[l]=max (rob,notr);
    }
};
