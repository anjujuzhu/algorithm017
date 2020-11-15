学习笔记
### 字典树
  - Trie树，又称单词查找树或键树，是一种树型结构
    - 典型应用是用于统计和排序大量的字符串
    - 最大限度地减少无谓的字符串的比较，查询效率比哈希表高
    特点：
     - 结点本身不存在完整单词
     - 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串
     - 每个结点的所有子结点路径代表的字符都不相同
    核心：
     - 空间换时间
  - 结点结构
   ```c++
    struct TreeNode {
      bool isEnd;//该结点是否是一个串的结束
      TreeNode* next[26];//字母映射表
    }
   ```
#### 一次建树，多次查询
```C++
  //定义Trie树
  class Trie {
    private:
      bool isEnd;
      Trie* next[26];
    public:
      //方法
  }
  //插入 
    // - 从根结点的子结点开始与Word第一个字符进行匹配，一直匹配到前缀链上没有对应的字符，开始不断开辟新的结点，直到插入完Word的最后一个字符，同时将最后一个节点的isEnd = true
    void insert (string word) {
      Trie* node = this;
      for (char c : word) {
        if (node->next[c - 'a'] == NULL) {
          node->next[c - 'a'] = new Trie();
        }
        node = node->next[c - 'a'];
      }
      node->isEnd = true;
    }
  //查找 某个单词Word 是否存在在树中
    bool search (string word) {
      Trie* node = this;
      for (char c : word) {
        node = node->next[c - 'a'];
        if (node == NULL) {
          return false;
        }
      }
      return node->isEnd;
    }
  //前缀匹配 - 查找前缀，最后return true
    bool startsWith (string prefix) {
      Trie* node = this;
      for (char c : word) {
        node = node->next[c - 'a'];
        if (node == NULL) {
          return false;
        }
      }
      return true;
    }
```
### 单词查找II复杂度分析
  - all words -> 构建Trie tree
  - board DFS

### 并查集
  - 判断两两是不是一个集合的问题
```C++
//C/C++
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

//递归
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }


    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }


    int getCount() const {
        return count;
    }

```
### 初级搜索
 1. 朴素搜索
 2. 剪枝、双向BFS
  - 

### AVL树
 - 因为二叉树的复杂度跟树的深度有关系，因此所谓的“平衡因子”是为了记录高度差
 - 为了将高度差保持在绝对值为0-1之间（平衡AVL树），就有了四种旋转操作
 - 左旋、右旋、左右旋、右左旋
  - 右右子树--> 左旋
  - 左左子树--> 右旋 
  - 左右子树--> 左右旋 ： 先左旋，再右旋
  - 右左子树--> 右左旋 ： 先右旋，后左旋
### 红黑树
 - 掌握5点基本概念
