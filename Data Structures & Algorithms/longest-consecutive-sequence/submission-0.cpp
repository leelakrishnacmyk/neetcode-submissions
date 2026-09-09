class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int longest=0;
        for (int num:st){
          if (!st.count(num-1)){
           int  len=1;
            int curr=num;
            while(st.count(curr+1)){
              curr++;
              len++;
            }
            longest=max(len,longest);
          }
        }
        return longest;
    }
};
