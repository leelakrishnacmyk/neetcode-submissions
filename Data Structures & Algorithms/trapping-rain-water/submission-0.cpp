class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int water=0;
        int n=height.size();
        for (int i=0;i<n;i++){
          while(!st.empty() && height[st.top()]<height[i]){
            int bottom =st.top();
            st.pop();
            if (st.empty()){
              break;
            }
            int left=st.top();
            int right=i;
            int width=right-left-1;
            int h=min(height[left],height[right])-height[bottom];
            water+=h*width;
          }
          st.push(i);
        }
        return water;
    }
};
