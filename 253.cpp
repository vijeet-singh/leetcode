sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
    auto comp = [](vector<int> a, vector<int> b){return a[1] < b[1];};
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    pq.push(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        vector<int> current = intervals[i];
        vector<int> earliest = pq.top();
        if(current[0] >= earliest[1]){
            pq.pop();
            earliest[1] = current[1];
            pq.push(earliest);
        }
        else{
            pq.push(current);
        }
    }
    int ans = pq.size();
    return ans;
