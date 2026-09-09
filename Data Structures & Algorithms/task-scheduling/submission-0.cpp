class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int>mpp;
       int m=tasks.size();
       for (int i=0;i<m;i++) {
        mpp[tasks[i]]++;
       }
        priority_queue<int>pq;
        for (auto it:mpp){
            pq.push(it.second);
       }
       int time=0;
       while(!pq.empty()){
        vector<int>temp;
        for (int i=0;i<=n;i++){
            if (!pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;
                if (f>0){
                    temp.push_back(f);
                }
            }
            time++;
            if (pq.empty() && temp.empty()){
                break;
            }
        }
        for (int q:temp){
            pq.push(q);
        }
       }
       return time;
    }
};
