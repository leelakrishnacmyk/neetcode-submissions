class Solution {
public:
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
       string temp;
       vector<string>ans;
       solve(0,digits,temp,ans);
       if (digits.size()==0){
        return {};
       }
       return ans;
    }
    void solve(int i, string & digits , string& temp,vector<string>& ans){
        if (i==digits.size()){
            ans.push_back(temp);
            return ;
        }
        string letter=mp[digits[i]-'0'];
        for (char ch: letter){
            temp.push_back(ch);
            solve(i+1,digits,temp,ans);
            temp.pop_back();
        }
    }
};
