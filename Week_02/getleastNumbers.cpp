//堆
/*
*C++默认大顶堆
*创建大顶堆，放入k个数，然后不断替换堆顶元素
*最后堆内存放的就是k个最小值
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        priority_queue<int> heap;
        for (int i = 0; i < k; ++i) {
            heap.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (heap.top() > arr[i]) {
                heap.pop();
                heap.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};

/*
* 小顶堆（注意初始化）
* 将所有的数放入堆中，然后依次pop出前k个值
*/
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < arr.size(); ++i) {
        heap.push(arr[i]);
    }
    for (int i = 0; i < k; ++i) {
        res.push_back(heap.top());
        heap.pop();
    }
    return res;
}
