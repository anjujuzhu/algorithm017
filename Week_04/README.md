学习笔记

### 遍历 - 搜索

- 每个节点都要访问一次
- 每个节点仅仅访问一次
- 访问节点的顺序
  - 深度优先 DFS
  - 广度优先 BFS

- DFS Vs BFS总结
    - dfs 改变一步，到一个层级，在改变的基础上继续深入
    - bfs 改变一步，回退，去尝试这一步改变的其他思路，存起来，遍历完之后再去存储区拿出之前的所有探索路径，依次深入
        - dfs 借助递归  bfs 借助队列存储，具有回溯

#### DFS

- ​	![image-20201025125100072](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20201025125100072.png)

- ```C++
  //多叉树
  map<int, int> visited;
  
  void dfs(Node* root) {
      if (!root) return;
      
      if (visited.count(root->val)) {//如果该结点被访问过，就返回
          return;
      }
      
      visited[root->val] = 1;//如果没被访问，就记录该结点被访问
      
      for (int i = 0; i < root->children.size(); ++i) {
  		dfs(root->childred[i])//访问节点的子节点,多叉树情况
      }
      return;
  }
  
  //二叉树
  map<int, int> visited;
                        
  void dfs(Node* root) {
      if (!root) return;
      
      if (visited.count(root->val)) {
          return;
      }
      
      visited[root->val] = 1;
      
      dfs(root->left);
      dfs(root->right);
  }
  ```

### BFS

- python 使用数组，java 使用双端队列或者队列

- ```c++
  void bfs(Node* root) {
      map<int, int> vsited;
      if (!root) return;
      
      queue<Node*> queueNode;
      queueNode.push(root);
      
      while (!queueNode.empty()) {//只要队列不为空
          Node* node = queueNode.top();//取出队头节点
          queueNode.pop();
          
          if (visited.count(node->val)) continue;//如果被标记过就跳过
          visited[node->val] = 1;//否则，标记
          
          for (int i = 0; i < node->children.size(); ++i) {
  			queueNode.push(node->children[i]);//将子节点放入队列
          }
      }
      return;
  }
  ```

  ```js
  const visited = new Set();
  const dfs = node => {
      if (visited.has(node)) return;
      visited.add(node)
      dfs(node.left)
      dfs(node.right)
  }
  
  
  const bfs = (root) => {
      let result = [], queue = [root]
      while (queue.length > 0) {
          let level = [], n = queue.length;
          for (let i = 0; i < n; ++i) {
  			let node = queue.pop();
               level.push(node.val);
               if (node.left) queue.unshift(node.left);
               if (node.right) queue.unshift(node.right);
          }
          result.push(level)
      }
      return result;
  }
  ```

### 贪心算法 - 解决一些最优化问题

- 贪心算法和动态规划的不同在与对每个子问题的解决方案都做出选择，不能回退；动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能
    
- 贪心算法
    - coin change [20, 10, 5, 1]硬币存在一种整数倍数的关系，先用最大的去试，贪心法是有效
    - 比如 [10, 9, 1] 拼出18 = 9 + 9, 但是用贪心法，用10先去匹配，然后8个1，明显不是最优的
    - 重要的是证明贪心算法的结果是正确的（现实中很少有贪心是正确的）
    
    - 贪心算法的应用
        - 反向贪心，比如 跳跃游戏 从最后的元素last开始判断last-i的位置上能不能跳过来
        - 贪心算法做辅助

### 二分查找
 - 条件：
    - 单调的
    ```C++
        int left = 0, right = len(array) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
                break or return result;
            } else if (array[mid] < target) {
                left = mid++;
            } else {
                right = mid--;
            }
        }
    ```
#### 思考
 - 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
    - 