class Solution 
{ 
public:
    int maxPoints(vector<vector<int>>& points) 
    {   //对每个点。遍历，找斜率相同的。注意重复点
        int n = points.size();
        if (n < 3)
            return n;
        int res = 0;
        for (int i = 0; i < n; i ++)
        {
            int repeat_cnt = 0;
            int cur_max = 0;
            unordered_map<string, int> slope_cnt;   //用小数，有例子通不过，可能是精度不够
            for (int j = i + 1; j < n; j ++)
            {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    repeat_cnt ++;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int tmp = self_gcd(dx, dy); 
                //库函数不行，std::gcd()只返回正数。非要的话，要判断正负号。比如（4，-6）和（-4,6）是一条线上的
                string slope = to_string(dx / tmp) + '/' + to_string(dy / tmp);

                slope_cnt[slope] ++;
                cur_max = max(cur_max, slope_cnt[slope]);
            }
            res = max(res, cur_max + repeat_cnt + 1);
        }
        /*
        cout << gcd(4, -6) << endl;         //2
        cout << gcd(-4, 6) <<endl;          //2
        cout << self_gcd(4, -6) << endl;    //-2
        cout << self_gcd(-4, 6) << endl;    //2
        cout << self_gcd(-4, -6) << endl;   //-2
        */
        return res;
    }

    int self_gcd(int a, int b)  //正负号取决于，b的符号。
    {
        if (b == 0)
            return a;
        return self_gcd(b, a%b);
    }
};

