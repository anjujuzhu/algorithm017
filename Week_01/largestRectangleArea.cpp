// 柱状图中最大面积
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int len = heights.size();
      if (len == 1) {
          return heights[0];
      }
      stack<int> s;//store the index
      int area = 0;
      for (int i = 0; i < len; ++i) {
        while ( !s.empty() && heights[i] < heights[s.top()] ) {
          int height = heights[s.top()];
          s.pop();
          int width = i;
          if ( !s.empty() ) {
            width = i - s.top() - 1;
          }
            area = max(area, height * width);
        }
        s.push(i);
      }
      while ( !s.empty() ) {
        int height = heights[s.top()];
        s.pop();
        int width = len;
        if ( !s.empty() ) {
          width = len - s.top() - 1;
        }
        area = max(area, width * height);
      }
      return area;
    }
};
//k个数划窗中的最大值
/******暴力解法********/
