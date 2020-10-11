学习笔记

### 树

```python
#前序遍历 根-左-右
def preorder(self, root):
	if root:
		self.traverse_path.append(root.val)
		self.preorder(root.left)
		self.preorder(root.right)
#中序遍历 左-根-右
def inorder(self, root):
	if root:
		self.inorder(root.left)
		self.traverse_path.append(root.val)
		self.inorder(root.right)
#后序遍历 左-右-根
def postorder(self, root):
	if root:
		self.postorder(root.left)
		self.postorder(root.right)
		slef.traverse_path.append(root.val)
```

### 堆 Heap

- 可以迅速找到一堆数中的最大或者最小值的数据结构
- 根节点最大的堆叫做大顶堆或大根堆，根节点最小的堆叫做小顶堆或者小根堆，常见的是二叉堆或者斐波那契堆
- 假设大顶堆，常见API
  - find-max		O(1)
  - delete-max    O(logN)
  - insert(creat)   O(logN) or O(1)

![image-20201009204601677](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20201009204601677.png)

### 二叉堆

- 完全二叉树实现，不是二叉搜索树，二叉搜索树在找最小值的时候，不是O(1)，而是O(logN)
- 两个性质
  - 根节点最大
  - 

- #### 实现细节

  - 利用数组实现
  - 根节点（顶堆元素）：a[0]
  - 索引为 **i** 的左孩子的索引是（2 * i + 1）
  - 索引为 **i** 的左孩子的索引是 （2 * i + 2）
  - 索引为 **i** 的父结点的索引是floor（（i - 1）/ 2）

![image-20201009205459227](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20201009205459227.png)

- Insert
  - 简单插入堆尾，然后向上浮动
    - 时间复杂度，最坏情况下就是树的深度，log2N

- Delete - max
  - 将最后一个节点替代根节点
  - 从根部向下调整整个堆的结构（一直到堆尾即可）

**系统自带的PriorityQueue 是 heap 的一种常见简单的实现**

- C++ 中堆，即优先队列是大根堆
- python里面为小根堆


