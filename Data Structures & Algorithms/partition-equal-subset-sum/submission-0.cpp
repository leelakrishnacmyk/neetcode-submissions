class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int n:nums){
            sum+=n;
        }
        if (sum%2){
            return false;
        }
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
       return  solve(0,target,nums,dp);
    }
    bool solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if (target==0){
          return true;
        }
        if (idx==nums.size()){
            return false;
        }
        if (dp[idx][target]!=-1){
            return dp[idx][target];
        }
        bool nottake=solve(idx+1,target,nums,dp);
        bool take=0;
        if (nums[idx]<=target){
             take=solve(idx+1,target-nums[idx],nums,dp);
        }
        return dp[idx][target]=nottake|| take;
    }

};
