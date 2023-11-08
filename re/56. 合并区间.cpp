class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        if (intervals.size() == 0) return res;
        for (auto interval :  intervals) {
            if(res.size() == 0 || interval[0] > res.back()[1]) {
                res.push_back(interval);
                continue;
            }
            int start = res.back()[0];
            int end = max(interval[1],res.back()[1]);
            res.back() = {start,end};
        }
        return res;
    }
};
