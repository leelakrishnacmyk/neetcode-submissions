class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
   int sum=1;
   int n=nums.size();
   vector<int>ans;
   int cnt=0;
   for (int i=0;i<n;i++){
   
    if (nums[i]==0){
        cnt++;
    }else{
         sum=sum*nums[i];
    }
   }
   for (int j=0;j<n;j++){
    if (cnt==0){
    int temp=sum/nums[j];
    ans.push_back(temp);
    }else if(cnt==1) {
        if (nums[j]==0){
      ans.push_back(sum);
        }else{
            ans.push_back(0);
        }
    }else {
        ans.push_back(0);
    }
   }
    return ans;
    }
   
};
