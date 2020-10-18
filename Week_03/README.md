学习笔记

### 树的面试题解法一般都是递归 1.节点的定义 2.重复性（自相似性）

```java
//泛型递归 
public void recur(int level, int param) {
  //terminator
  if (level > MAX_LEVEL) {
    //process result
    return;
  }

  //process current logic
  process(level, param);

  //drill down
  recur(level:level + 1, newParam)

  //restore current status
}
```

- 不要人肉递归
- 找重复性
- 数学归纳法的思想

### 递归总结

- 泛型递归如上，直接操作数据
- 更多是有返回类型的，比如TreeNode*  functionName()，要找好重复事件

**从前序与中序遍历序列中构造二叉树**

- preorder：[根结点，左子树序列，右子树序列]
- inorder：[左子树序列，根结点，右子树序列]
- 从前序里确定根结点，从中序中由根结点的左侧确定左子树，右侧为右子树

### 分治

- 指定数字n的M次阶乘，递归时间复杂度O(M)
- 分治就是O(logM）

```C++
//分治C/C++
int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}
```

### 回溯

- 一种通过探索所有可能的候选解来找出所有的解的算法。如果候选解被确认不是一个解的话（或者至少不是最后一个解），回溯算法会通过在上一步进行一些变化抛弃该解，即回溯并且再次尝试。


