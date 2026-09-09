class Solution {
public:
vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
         vector<string> temp;
        solve(s, 0, temp);
        return ans;
    }
 bool ispalindrome(string &s , int l,int r){
    while(l<r){
        if (s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true ;
 }
  void solve (string &s , int i,vector<string>&temp){
    if (i==s.size()){
        ans.push_back(temp);
        return ;
    }
    for ( int j=i;j<s.size();j++){
        if (ispalindrome(s,i,j)){
            temp.push_back(s.substr(i,j-i+1));
            solve(s,j+1,temp);
            temp.pop_back();
        }
    }
  }

};
