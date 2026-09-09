class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int left=0;
        int ans=0;
        int maxFreq=0;
        for ( int right=0;right<s.size();right++){
            mpp[s[right]]++;
          maxFreq=max(maxFreq,mpp[s[right]]);
          while((right-left+1) > maxFreq+k ){
            mpp[s[left]]--;
            left++;
          }
          ans=max(ans,right-left+1);
        }
        return ans;
    }
};
