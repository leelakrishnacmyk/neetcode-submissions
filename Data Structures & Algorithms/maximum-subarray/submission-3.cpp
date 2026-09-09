class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int maxsum=nums[0];
     for (int i=1;i<nums.size();i++){
      maxsum=max(nums[i],nums[i]+maxsum);
      maxi=max(maxi,maxsum);
     }
     return maxi;
    }
};
