class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;
        vector<int>ans;
        for (int right=0;right<nums.size();right++){
            if  (right-left+1==k ){
              int maxi=*max_element(nums.begin()+left,nums.begin()+right+1);
              ans.push_back(maxi);
              left++;
            }
            
        }
        return ans;
    }
};
