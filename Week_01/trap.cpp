//维护栈，横格累加面积
class Solution {
public:
    int trap(vector<int>& height) {
        //维护一个栈，一直变小就压栈，遇到比top值大的值就 计算雨水 累加，新入的值要一直循环比较，直到没有比自己 小的值在栈中
        stack<int> s;
        int area = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int temp = s.top();
                s.pop();
                if (s.empty()) break;//这一点一定要注意
                int width = i - s.top() - 1;
                int high = min(height[i], height[s.top()]) - height[temp];
                area += high * width;
            }
            s.push(i);
        }
        return area;
    }
};

