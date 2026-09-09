class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
    void solve (int i,vector<int>& nums){
     ans.push_back(temp);
     for (int j=i ;j<nums.size();j++){
        if (j>i && nums[j]==nums[j-1]){
            continue;
        }
        temp.push_back(nums[j]);
        solve(j+1,nums);
        temp.pop_back();
     }
    }
    
};
