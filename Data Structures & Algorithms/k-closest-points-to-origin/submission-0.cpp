class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        for (int i=0;i<points.size();i++){
            int first=points[i][0];
            int second=points[i][1];
            int dist=first*first+second*second;
            pq.push({dist,i});
            if (pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
