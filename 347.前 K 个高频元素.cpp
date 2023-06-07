class Solution {
public:
    class compare {
     public:
        bool operator() (const pair<int,int> &lhs,const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
    // 所以我们要用小顶堆，因为要统计最大前k个元素，只有小顶堆每次将最小的元素弹出，最后小顶堆里积累的才是前k个最大元素。
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> que;
        for (auto it = hash.begin(); it != hash.end(); it ++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = que.top().first;
            que.pop();
        }
        return res;
    }
};
