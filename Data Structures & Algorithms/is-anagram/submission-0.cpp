class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if (n!=m){
            return false;
        }
       unordered_map<char,int>mpp;
       for (int i=0;i<n;i++){
        mpp[s[i]]++;
       } 
       for (int j=0;j<n;j++){
        mpp[t[j]]--;
       }
       for (auto&p:mpp){
        if (p.second!=0){
            return false;
        }
       }
       return true;
    }
};
