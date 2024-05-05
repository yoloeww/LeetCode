class Solution { 
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1,res = 0;

        // 选定两板高度中的短板，向中间收窄一格；
        while (i < j) {
            res = height[i] < height[j] ?
            max(res,(j - i) * height[i ++]) :
            max(res,(j - i) * height[j --]);
        }
        return res;
    }
};
