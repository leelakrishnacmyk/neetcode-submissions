class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        for (int i=0;i<position.size();i++){
         cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        });
        double acttime=0;
        int cnt=0;
        for (auto & car:cars){
           double time= (double)(target-car.first)/car.second;
          if (time>acttime){
            cnt++;
            acttime=time;
          }
        }
        return cnt;
    }
};
