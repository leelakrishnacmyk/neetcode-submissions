class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
     vector<pair<int,int>>ans;
     for (int i=0;i<position.size();i++){
        ans.push_back({position[i],speed[i]});
     }
     sort(ans.begin(),ans.end(),[](auto  & a,auto &b) {
        return a.first>b.first;
     });
     int fleets=0;
     double lasttime=0;
     for (int i=0;i<position.size();i++){
         double time =(double)( target-ans[i].first)/ans[i].second;
        if (lasttime < time){
            fleets++;
           lasttime=time ;
        }
     }
     return fleets;
    }
};
