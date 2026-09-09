class Solution {
public:
vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0, nums, target, temp);
        return ans;
    }
    void solve (int i , vector<int>& nums,int target ,vector<int> temp){
        if (target==0){
            ans.push_back(temp);
            return ;
        }
        for (int j=i;j<nums.size();j++){
            if (nums[j]>target){
                continue ;
            }
            temp.push_back(nums[j]);
            solve(j,nums,target-nums[j],temp);
            temp.pop_back();
        }

    }
};
