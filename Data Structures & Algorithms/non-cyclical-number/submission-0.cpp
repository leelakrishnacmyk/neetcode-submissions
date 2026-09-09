class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1 && !st.count(n)){
            st.insert(n);
           n= solve(n);
        }
        return n==1;
    }
    int solve(int n){
        int sum =0;
        while(n>0){
        int digit=n%10;
        sum+=digit*digit;
        n=n/10;
        }
        return sum ;
    }
};
