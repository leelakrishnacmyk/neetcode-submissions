class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       vector<int> pse = ps(heights);
        vector<int> nse = nextSmaller(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = nse[i] - pse[i] - 1;
            maxi = max(maxi, width * heights[i]);
        }
        return maxi;
    }  
    
    vector<int> ps(vector<int>& heights){
        stack<int>st1;
        vector<int>pse;
        for (int i=0;i<heights.size();i++){
          while(!st1.empty() && heights[st1.top()]>=heights[i]){
            st1.pop();
          }
         if (st1.empty()){
            pse.push_back(-1);
         }else {
            pse.push_back(st1.top());
         }
         st1.push(i);
        }
        return pse;
    }
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }
};
