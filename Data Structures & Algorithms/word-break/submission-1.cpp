class Solution {
public:
unordered_set<string>st;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        st.insert(wordDict.begin(),wordDict.end());
        return solve(0,s,dp);
    }
    bool solve (int index,string s,vector<int>&dp){
        if (index==s.size()){
            return true;
        }
        if (dp[index]!=-1){
            return dp[index];
        }
        for (int i=index;i<s.size();i++){
          string word=s.substr(index,i+1-index);
          if (st.count(word)){
           if (solve(i+1,s,dp)){
            return dp[index]= true;
           }
          }
        }
        return dp[index]=false;
    }
};
