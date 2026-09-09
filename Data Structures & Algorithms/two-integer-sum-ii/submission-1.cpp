class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for (int i=0;i<n;i++){
         int need=target-nums[i];
         if (mpp.count(need) ){
          return {mpp[need]+1,i+1};
         }
         mpp[nums[i]]=i;
        }
        return {};
    }
};
