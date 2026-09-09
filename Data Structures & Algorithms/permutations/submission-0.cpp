class Solution {
public:
vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
      vector<int>temp;
      vector<bool>used(nums.size(),false);
      solve(nums,temp,used);
      return ans;  
    }
    void solve(vector<int>& nums,vector<int>& temp,vector<bool> &used ){
        if (temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        for (int j=0;j<nums.size();j++){
            if (used[j]){
                continue;
            }
            used[j]=true;
            temp.push_back(nums[j]);
            solve(nums,temp,used);
            temp.pop_back();
            used[j]=false;

        }
    }
};
