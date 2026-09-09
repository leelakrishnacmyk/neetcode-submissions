class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
            if (s1.size()>s2.size()){
                return false;
            }
        for (int i=0;i<s1.size();i++){
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        if (mpp1==mpp2){
            return true ;
        }
        for (int j=s1.size();j<s2.size();j++){
            mpp2[s2[j]]++;
            mpp2[s2[j-s1.size()]]--;
            if (mpp2[s2[j-s1.size()]]==0){
                mpp2.erase(s2[j-s1.size()]);
            }
            if (mpp1==mpp2){
                return true ;
            }
        }
        return false;
    }
};
